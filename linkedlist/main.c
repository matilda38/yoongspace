/* run: ctrl+R */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    자료의 논리적인 순서와 물리적인 순서가 일치하지 않는 자료구조

    각 원소에 저장되어 있는 다음 원소의 주소에 의해 순서가 연결되는 방식

    물리적인 순서를 맞추기 위한 오버헤드가 발생하지 않음

    여러 개의 작은 공간을 연결하여 하나의 전체 자료구조를 표현

    크기 변경이 유연하고 더 효율적으로 메모리를 사용
    Linked list를 구현해보자

    아래와 같은 출력이 되도록 구현해 보자

    빈 리스트 생성 후 빈 리스트 출력
    3개가 추가된 리스트 출력
    노드 한 개 추가 후 출력
    마지막 노드 삭제 후 출력
    역순으로 변환 후 출력
    리스트 공간을 해제한 후 출력

    */

    //list역할.
    typedef struct Node{
        char data[10];
        struct Node* link;
    }Node;

    //list의 header역할.
    typedef struct Node_h{
        Node* head;
    }Node_h;

    //공백 리스트 생성.(header를 가리키는 포인터를 반환한다.)
    Node_h* createList(){
        Node_h* L;
        L=(Node_h*)malloc(sizeof(Node_h));
        L->head=NULL;
        return L;
    }

    void InsertLastNode(Node_h* list, char* x){
        //삽입할 신규 노드 생성
        //1. null을 가진 헤드노드에 삽입하는경우
        //2. 기존 노드를 가진 리스트에 삽입하는 경우

        Node* node_n;
        Node* pointer;

        node_n=(Node*)malloc(sizeof(Node)); //메모리 할당.
        strcpy(node_n->data, x);
        node_n->link= NULL;

        if(list->head==NULL){
            list->head= node_n;
            return;
        }
        pointer=list->head;
        while(pointer->link!=NULL)pointer=pointer->link;
        pointer->link=node_n;
    }
    void deleteLastNode(Node_h* L){
        //마지막 노드 삭제
        //1. 공백리스트의 삭제
        //2. 공백이 아닌 리스트의 노드 삭제
        // a. 1개의 노드가 있을때
        // b. 2개 이상.
        Node* pointer;
        Node* prev;
        if(L->head==NULL) return;
        if(L->head->link==NULL){
            free(L->head);
            L->head=NULL;
            return;
        }
        pointer=L->head;
        prev=L->head;
        while(prev->link->link!=NULL)prev=prev->link;
        free(prev->link);
        prev->link=NULL;
    }

    void freeList(Node_h* L){
        Node* pointer; //따라갈 포인터 생성
        while(L->head!=NULL){//공백 리스트가 아니면 계속 돈다.
            pointer=L->head;//해제할 리스트의 첫번째 노드 주소를 넣는다.
            free(pointer);//해당 노드 free
            pointer=NULL;
            L->head=L->head->link; //다음 노드의 주소를 head로!
        }
    }

    void printList(Node_h* L){
        Node* pointer;
        pointer= L-> head;
        printf("[");
        while(pointer!=NULL){
            printf("%s",pointer->data);
            pointer=pointer->link;
        }
        printf("]");
    }
    int main(){

        Node_h* L;
        L = createList();
        printf("빈 리스트 생성");
        printList(L);

        getchar();

        printf("리스트에 3개의 노드 추가하기");
        InsertLastNode(L,"월");
        InsertLastNode(L,"수");
        InsertLastNode(L,"금");

        getchar();

        printList(L);getchar();

        printf("리스트에 1개의 노드 삭제하기!");getchar();
        deleteLastNode(L);
        printList(L);getchar();

        printf("리스트 memory 해제하기!");getchar();
        freeList(L);
        printList(L);

        return 0;
    }
