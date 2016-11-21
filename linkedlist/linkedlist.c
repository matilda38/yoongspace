#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int domain_id;
    struct _node* next_node;
} node;

node* CreateVMList(){
    node* head;//the head of the list
    head= (node*)malloc(sizeof(node));
    head->domain_id=0; //domain0
    head->next_node=NULL;
    return head;
}

void AddDomain(node* head, int newdomain_id){
    node* node_ptr = head;

    node* NewDomain= (node*)malloc(sizeof(node));
    NewDomain->domain_id= newdomain_id;

    if(head==NULL){
        head = NewDomain;
    }

    while(node_ptr->next_node!=NULL) node_ptr = node_ptr->next_node;
    node_ptr->next_node=NewDomain;
}

void DeleteDomain(node* head, int deletedomain_id) {
    node *node_ptr = head;

    //다음 노드의 도메인 아이디가 삭제할 도메인아이디
    while (node_ptr->next_node->domain_id != deletedomain_id) node_ptr = node_ptr->next_node;

    //삭제할 노드의 다음 노드 주소를 전 노드의 다음 노드 값으로 대입한다.
    node_ptr->next_node = node_ptr->next_node->next_node;
}

int main(){
    node* seVM_h=CreateVMList();//header for seVM List
    node* scVM_h=CreateVMList();//header for scVM List


}
