#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
  int data;
  struct _node* next;
}node;

typedef struct _list{
  int count;
  node* head;
}list;

void initList(list* List){
  List->count = 0;
  List->head = NULL;
}
//멤버함수 불가능 -> 포인터 개념 적극활용.

void insert(list* List, int data, int position){
  int i;
  if(position < 0 || position > (List->count) + 1){
    printf("위치를 잘못 입력하셨습니다.\n");
    return;
  }
  node* newNode = (node*)malloc(sizeof(node));
  newNode->data = data;
  if(position == 1){
    newNode->next = List->head;
    List->head = newNode;
  }
  else{
    node* temp = List->head;
    for(i=1;i<position-1;i++){
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
  }
  List->count++;
}

int search(list* List, int data)
{
    int i = 1;
    if(List->count == 0){
      printf("리스트가 비었습니다.");
      return 0;
    }
    else{
      node* nodeptr = List->head;
      while(nodeptr->data != data){
        if(nodeptr == NULL){
          printf("검색결과가 없습니다.");
          return 0;
        }
        nodeptr = nodeptr->next;
        i++;
      }
      printf("검색결과: %d\n in position %d\n", nodeptr->data, i);
      return i;
    }
}

void delete(list* List, int position){
  int i;
  if(position < 0 || position > List->count){
    printf("위치를 잘못 입력하셨습니다.\n");
    return;
  }
  else{
    node* temp = List->head;
    if(position == 1){
      List->head = List->head->next;
      free(temp);
    }
    else{
      for(i=1;i<position-1;i++){
        temp = temp->next;
      }
      node* deletenode = temp->next;
      temp->next = temp->next->next;
      free(deletenode);
    }
  }
  List->count--;
}

void deletebysearch(list* List, int data){
  int position = search(List, data);
  delete(List, position);
}

void printList(list* List){
  node* temp = List->head;
  while(temp != NULL){
    printf("%d ",temp->data);
    printf("\n");
    temp = temp->next;
  }
}

int main()
{
  list* List = (list*)malloc(sizeof(list));
  initList(List);

  insert(List, 1, 1);
  printList(List);

  insert(List, 2, 2);
  insert(List, 4, 3);
  insert(List, 8, 4);
  insert(List, 16, 5);

  printList(List);

  delete(List, 3);
  printList(List);

  deletebysearch(List, 8);

  printList(List);
  free(List);

  return 0;
}
