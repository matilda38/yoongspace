//
// Created by 황나윤 on 2016. 10. 13..
//

#include <stdio.h>
#include <stdlib.h>

//주소로 접근하기 때문에 전역변수가 필요없음.
typedef int element;

typedef struct StackNode{
    element data;
    struct StackNode* link;
}Stack;

//마지막 stacknode를 가르키게 될 top 포인터.
StackNode* top;

void push(element data_in){
    //일단 노드를 생성한다.
    StackNode* temp=(StackNode *)malloc(sizeof(StackNode));
    temp->data= data_in;
    //top에 전 노드의 주소값이 있으므로 link에 해당 값을 입력한다.
    temp->link= top;
    //새로운 노드의 주소를 top에 입력한다.
    top=temp;
}
element pop(){
    //공백리스트라면,
    if(top==NULL){
        printf("\n empty stack\n");
        return 0;
    }
    //아니라면,
    //기존 노드의 data, link를 복사해둔다.
    element data_o=top->data;
    StackNode* link=top->link;
    StackNode* tmp=top;

    free(tmp);
    top=link;
    return data_o;
}
void del(){
    if(top==NULL){
        printf("\n empty stack\n");
        return;
    }
    StackNode* tmp=top;
    top=top->link;
    free(tmp);
}
void printStack(){
    StackNode* tmp=top;
    printf("Stack: [");
    while(tmp!=NULL){
        printf("%d",tmp->data);
        tmp=tmp->link;
    }
    printf("]");
}
int main(){
    top=NULL;
    printStack();

    push(1);
    getchar();
    printStack();
    getchar();

    push(2);
    printStack();
    getchar();

    push(3);
    printStack();
    getchar();

    push(4);
    printStack();
    getchar();

    del();
    printStack();
    getchar();

    del();
    printStack();
    getchar();

    printf("data popped is: %d",pop());
    getchar();

    printStack();

    getchar();
    return 0;
}

