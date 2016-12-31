#include<stdio.h>
#include<stdlib.h>
#include<l

typedef struct _node{
    int domain_id;
    int useCPU;
    int useMem;

    struct _node* next_node;
} node;

node* CreateVMList(){
    node* head= (node*)malloc(sizeof(node));
    head->domain_id=0; //domain0
    head->next_node=NULL;
    return head;
}

void AddDomain(node* head, int newdomain_id){
    node* node_ptr = head;

    node* NewDomain= (node*)malloc(sizeof(node));

    //새로운 노드인 new domain에 id와 다음 노드 주소값을 부여한다
    NewDomain->domain_id= newdomain_id;
    NewDomain->next_node= NULL;

    if(head==NULL){
        (*head) = *NewDomain;
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

void PrintList(node* head){
    node* node_ptr= head;
    while(node_ptr->next_node!=NULL) {
        printf("%d\n", node_ptr->domain_id);
        node_ptr = node_ptr->next_node;
    }
}

int main(){
    node* seVM_h=CreateVMList();//header for seVM List
    node* scVM_h=CreateVMList();//header for scVM List
    /*
    AddDomain(seVM_h, 1);
    AddDomain(seVM_h, 2);
    AddDomain(seVM_h, 3);
    AddDomain(seVM_h, 4);

    PrintList(seVM_h);
    */

    /*
    int i;
    int numDomains;
    int *activeDomains;

    virConnectPtr conn;
    conn = virConnectOpen("xen:///system");

    if (conn == NULL) {
        fprintf(stderr, "Failed to open connection to qemu:///system\n");
        return 1;
    }

    numDomains = virConnectNumOfDomains(conn);

    activeDomains = malloc(sizeof(int) * numDomains);
    numDomains = virConnectListDomains(conn, activeDomains, numDomains);

    //activeDomains[]는 활성화된 도메인의 id가 담긴 배열입니다.
    //모든 active domain들을 일단 seVM list에 넣습니다.
    for (i = 0 ; i < numDomains ; i++) {
        AddDomain(seVM_h, activeDomains[i]);
    }
    free(activeDomains);
    */

    return 0;

}
