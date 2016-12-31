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
#define OP_PUSH             ((unsigned char)0x03)
#define OP_DIGEST           ((unsigned char)0x04)

//발신용 변수. static 배열이므로 자동 초기화된다
char buf[1024];//1024 byte //store
//char data_str[1024];

//수신 용 변수.
//받는 버퍼, SEQUENCE_NUM, DATA_LENGTH, OP.
char buf_get[1024];
char data_str_get[12288];
unsigned short sequence_number;
unsigned int data_length;
char hash_out[20];


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
    int full_length=0;
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

    //hello message
    send(client_sockfd, buf, 1023,0);
    recv(client_sockfd, buf_get,1023,0);

    memset(buf_get, '\0', sizeof(buf_get));
    memset(buf, '\0', sizeof(buf));

    int i;

    //real message
    recv(client_sockfd, buf_get, 1023, 0);

    if (buf_get[0] == FLAG_INSTRUCTION){
        while (buf_get[0] != FLAG_TERMINATE) {
            //sequence_number = ntohs(*(unsigned short *)(buf_get + 2));//static 변수 sequence_number
            if(buf_get[1] == OP_PUSH){
                //static 변수 sequence_number
                sequence_number = ntohs(*(unsigned short *)(buf_get + 2));
                data_length = ntohl(*(int *)(buf_get + 4));

                //data field
                //sequence number가 50..
                for (i = 0; i < data_length; i++)
                    data_str_get[sequence_number + i] = (buf_get + sizeof(struct header))[i];

                full_length += data_length;

                //response
                header_p->flags = FLAG_RESPONSE;
                header_p->op = OP_PUSH;
                header_p->seq_num = htons(0);
                header_p->data_len = htonl(0);

                memcpy(buf, header_p, sizeof(struct header));

                for(i=sizeof(struct header);i<1024;i++){
                    buf[sizeof(struct header)]='\0';
                }

                send(client_sockfd, buf, 1023, 0);
            }
            else if(buf_get[1] == OP_DIGEST){
                //response
                header_p->flags = FLAG_RESPONSE;
                header_p->op = OP_DIGEST;
                header_p->seq_num = htons(0);
                header_p->data_len = htonl(20);

                SHA1(hash_out, data_str_get, full_length);

                memcpy(buf, header_p, sizeof(struct header));
                memcpy(buf + sizeof(struct header), hash_out, 20);//data field 비우기

                send(client_sockfd, buf, 1023, 0);
            }

            memset(buf_get, '\0', sizeof(buf_get));
            memset(buf, '\0', sizeof(buf));

            read(client_sockfd, buf_get, 1023);
        }
    }

    close(client_sockfd);

    return 0;
}