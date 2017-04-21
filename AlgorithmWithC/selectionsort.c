#include<stdio.h>

void SelectionSort(int* arr, int size){
  int i, j;
  int temp;
  int mindex = 0;

  for(i=0;i<size;i++){
    for(j=i+1;j<size;j++){
      if(arr[mindex] > arr[j])
        mindex = j;
    }
    temp = arr[i];
    arr[i] = arr[mindex];
    arr[mindex] = temp;
  }

}
int main(){
  int arr[100];
  int i;

  for(i=100;i>0;i--){
    arr[100-i] = 3*i*i - 3*i;
  }

  for(i = 0;i < 100;i++){
    printf("%d ",arr[i]);
  }

  int size = sizeof(arr)/sizeof(arr[0]);

  SelectionSort(arr,size);

  printf("\n");

  for(i = 0;i < 100;i++){
    printf("%d ",arr[i]);
  }
  return 0;
}
