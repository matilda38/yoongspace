#include<stdio.h>

void SelectionSort(int* arr, int size){
  int i, j, k;
  for(i=1;i<size;i++){
    int data = arr[i];
    for(j=0;j<i;j++){
      if(arr[j] > arr[i]){
        for(k=i;k>j;k--){
          arr[k] = arr[k-1];
        }
        arr[j]=data;
        break;
      }
    }
  }
}

int main(){
  int arr[10] = {5, 4, 3, 2, 4, 6, 7, 3, 5, 1};

  for(int i=0;i<10;i++){
    printf("%d ",arr[i]);
  }

  SelectionSort(arr, 10);
  printf("After\n");
  for(int i=0;i<10;i++){
    printf("%d ",arr[i]);
  }

  return 0;
}
