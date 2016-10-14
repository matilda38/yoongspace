#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100


//전역변수 선언, 어디서든지 접근 가능(소스파일내).
typedef int element;
element stack[STACK_SIZE];
int top=-1; //공백.

//스택의 삽입 1. 꽉찼다 2. 그 외
void push(element item){
    if(top>=STACK_SIZE-1){
        printf("\n stack is full\n");
        return;
    }
    stack[++top]=item;
}

// 스택의 삭제. 1. 없다, 공백 스택 2. 그외
element pop(){
    if(top==-1){
        printf("\nStack is empty\n");
        return 0;
    }
    return stack[top--];
}
void del(){
    if(top==-1){
            printf("\nStack is empty\n");
        return;
    }
    top--;
}
void printStack(){
    int i;

    if(top==-1){
        printf("\nStack is empty\n");
        return;
    }

    printf("\nStack[");
    for(i=0;i<=top;i++){
        printf("%d",stack[i]);
    }
    printf("]\n");
}
int main(){
    printStack();
    push(1);
    printStack();
    push(2);
    printStack();
    push(3);
    printStack();

    push(4);
    printStack();

    printf("deleted item: %d",pop());


    printStack();
    del();
    printStack();

return 0;

}
