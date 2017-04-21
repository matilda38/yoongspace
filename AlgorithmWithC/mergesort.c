#include<stdio.h>

#define LISTSIZE 30

void merge(int* a, int i1, int i2, int j1, int j2);
void mergesort(int* a, int begin, int end);
int main(){
  int i, N;
  int arr[LISTSIZE];
  printf("배열 크기를 입력해주세요\n");
  scanf("%d",&N);

  printf("배열을 입력하세요\n");

  for(i=0;i<N;i++)
    scanf("%d", &arr[i]);

  mergesort(arr,0,N-1);

  for(i=0;i<N;i++)
    printf("%d ", arr[i]);
  
  return 0;
}
void mergesort(int* a, int begin, int end){
  int mid;
  if(begin<end){
    mid = (begin+end)/2;
    mergesort(a, begin, mid);
    mergesort(a, mid+1, end);
    merge(a,begin,mid,mid+1,end);
  }
}
void merge(int* a, int i1, int i2, int j1, int j2){
  int i,j,k;
  int temp[50];
  k = 0;
  i = i1;
  j = j1;
  while(i <= i2 && j <= j2){
    if(a[i] < a[j])
      temp[k++] = a[i++];
    else
      temp[k++] = a[j++];
  }
  while(i <= i2){
    temp[k++] = a[i++];
  }
  while(j <= j2){
    temp[k++] = a[j++];
  }

  for(i=0;i<k;i++){
    a[i] = temp[i];
  }
}
