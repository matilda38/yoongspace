#include <iostream>
#include <time.h>

using namespace std;

void prime(int num){
  clock_t begin, end;
  begin = clock();

  int* arr = new int[num];

  int i = 2;
  //initalize
  for(i=2;i < num; i++){
    arr[i] = i;
  }
  for(i=2;i<num;i++){
    if(arr[i]==0)
      continue;
    for(int j=i+i;j<num;j+=i){
      arr[j] = 0;
    }
  }

  for(i=2;i<num;i++){
    if(arr[i] != 0){
      cout << i;
      cout << " ";
    }

  }
  delete[] arr;

  end = clock();          // 시간설정
  cout<<"수행시간 : "<<((float)(end-begin)/CLOCKS_PER_SEC)<<endl;

}

void primesqrt(int num){
  clock_t begin, end;
  begin = clock();

  int* arr = new int[num];
  int i=3;
  int j=2;

  arr[2] = 1;
  for(i=3;i<num;i++){
    arr[i] = 1;
  }

  for(i=3;i<num;i+=2){//3,5,7,9..
    for(j=2 ; j*j <= i; j++){
      if(i % j == 0){
        arr[i] = 0;
        break;
      }
    }
  }

  for(i=3;i<num;i+=2){
    if(arr[i] != 0){
      cout << i;
      cout << " ";
    }
  }
  delete[] arr;
  end = clock();          // 시간설정
  cout<<"수행시간 : "<<((float)(end-begin)/CLOCKS_PER_SEC)<<endl;
}
int main(){
  prime(300000);
  primesqrt(300000);
  return 0;
}
