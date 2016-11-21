#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define SERVER_PORT 47500


//FLAGS
#define FLAG_HELLO  ((unsigned char)0x01 << 7)
#define FLAG_INSTRUCTION    ((unsigned char)0x01 << 6)
#define FLAG_RESPONSE       ((unsigned char)0x01 << 5)
#define FLAG_TERMINATE      ((unsigned char)0x01 << 4)

//OPERATIONS
#define OP_ECHO_REQUEST     ((unsigned char)0x00)
#define OP_INCREMENT        ((unsigned char)0x01)
#define OP_DECREMENT        ((unsigned char)0x02)

//발신용 변수. static 배열이므로 자동 초기화된다
char buf[1024];//128 byte
char data_str[1024];

//수신 용 변수.
//받는 버퍼, SEQUENCE_NUM, DATA_LENGTH, OP.
char buf_get[1024];
char data_str_get[1024];
unsigned short sequence_number;
unsigned int data_length;

struct header{//total 8 byte
	unsigned char flags;
	// 8 bit. one of H I R T and 4 bit is empty

	unsigned char op;
	// 8 bit. 0x00: echo. 0x01: increment. 0x02: decrement. three instructions all need response

	unsigned short seq_num;
	// 16 bit. when response, send same seq_num as received packet.

	unsigned int data_len;
	// data's length.
};

int main()
{
	struct hostent *hp;
	struct sockaddr_in sin;

	//header_p와 data_int, data_long 총 3개의 포인터를 선언한다. malloc 을 통해 주소를 할당해주어야 뒤에서 에러가 나지 않는다.
	//header_p-> flag 등의 참조를 수행할때 header_p만 선언하면 쓰레기 값이 저장된 포인터를 참조하기때문에 segmentation error가 난다
	struct header *header_p = (struct header*)malloc(sizeof(struct header));
	int* data_int = (int*)malloc(sizeof(int));
	long long* data_long = (long long*)malloc(sizeof(long long));

	const char* host = "localhost"; //to avoid run-time error
	//used for data (2 kind- int, char)

	int client_sockfd;

	/* active open */
	if ((client_sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {//create socket
		perror("socket error");
		exit(1);
	}

	/* translate host name into peer's IP address */
	hp = gethostbyname(host);

	/* build address data structure */
	bzero((char *)&sin, sizeof(sin));
	sin.sin_family = AF_INET;
	bcopy(hp->h_addr, (char *)&sin.sin_addr.s_addr, hp->h_length);
	sin.sin_port = htons(SERVER_PORT);

	//client side first
	if (connect(client_sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0)
	{
		perror("simplex-talk: connect");
		close(client_sockfd);
		exit(1);
	}

	/* main loop: get and send lines of text */
	//inital hello message sending
	//to prevent segmentation fault
	header_p->flags = FLAG_HELLO;
	header_p->op = OP_ECHO_REQUEST;//0x00

	//bigger than 2 byte -> htons, htonl
	header_p->seq_num = htons((unsigned short)0);//0x00
	header_p->data_len = htonl(4);

	*data_long = htonl(2014190703);

	memcpy(buf, header_p, sizeof(struct header));
	memcpy(buf + sizeof(struct header), data_long, 8);

	send(client_sockfd, buf, 1023,0);
	recv(client_sockfd, buf_get,1023,0);

	int i;
	recv(client_sockfd, buf_get, 1023, 0);

	if (buf_get[0] == FLAG_INSTRUCTION){
		while (buf_get[0] != FLAG_TERMINATE) {
			memset(buf, '\0', sizeof(buf));
			sequence_number = ntohs(*(unsigned short *)(buf_get + 2));//static 변수 sequence_number

			if (buf_get[1] == OP_ECHO_REQUEST) {
				data_length = ntohl(*(int *)(buf_get + 4));
				//data field
				for (i = 0; i < data_length; i++)
					data_str_get[i] = (buf_get + sizeof(struct header))[i];
				//response
				header_p->flags = FLAG_RESPONSE;
				header_p->op = 0;

				//bigger than 2 byte -> htons, htonl
				//same as received packet. sequence_number, data_length.
				header_p->seq_num = htons((unsigned short)sequence_number);
				header_p->data_len = htonl(data_length);

				memcpy(buf, header_p, sizeof(struct header));
				memcpy(buf + sizeof(struct header), data_str_get, strlen(data_str_get) + 1);

				send(client_sockfd, buf, 1023, 0);
			}
			else if (buf_get[1] == OP_INCREMENT) {
				*data_int = ntohl(*(int *)(buf_get + sizeof(struct header)));
				//to prevent segmentation fault
				header_p->flags = FLAG_RESPONSE;
				header_p->op = 0;

				//bigger than 2 byte -> htons, htonl
				//same as received packet. sequence_number, data_length.
				header_p->seq_num = htons((unsigned short)sequence_number);
				header_p->data_len = htonl(4);

				*data_int = *data_int + 1;
				*data_int = htonl(*data_int);a


				memcpy(buf, header_p, sizeof(struct header));
				memcpy(buf + sizeof(struct header), data_int, 4);
				send(client_sockfd, buf, 1023, 0);

			}
			else if (buf_get[1] == OP_DECREMENT) {
				*data_int = ntohl(*(int *)(buf_get + sizeof(struct header)));
				//make_response_decrement
				//to prevent segmentation fault
				header_p->flags = FLAG_RESPONSE;
				header_p->op = 0;

				//bigger than 2 byte -> htons, htonl
				//same as received packet. sequence_number, data_length.
				header_p->seq_num = htons((unsigned short)sequence_number);
				header_p->data_len = htonl(4);
				*data_int = *data_int - 1;
				*data_int = htonl(*data_int);

				memcpy(buf, header_p, sizeof(struct header));
				memcpy(buf + sizeof(struct header), data_int, 4);
				send(client_sockfd, buf, 1023, 0);
			}
			memset(buf_get, '\0', sizeof(buf_get));
			read(client_sockfd, buf_get, 1024);
		}
	}

	close(client_sockfd);

	return 0;
}