#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;


template <class TYPE>
void merge(vector<TYPE>& arr, vector<TYPE>& tmp, int start, int end){
  int mid  = (start+end)/2;
  int i = start;
  int k = start;
  int j = mid + 1;
  while(i <= mid && j <= end){
    if(arr[i] < arr[j]){
      tmp[k++] = arr[i++];
    }
    else{
      tmp[k++] = arr[j++];
    }
  }
  while(i <= mid){
    tmp[k++] = arr[i++];
  }
  while(j <= end){
    tmp[k++] = arr[j++];
  }

  for(i = start;i <= end; i++){
    arr[i] = tmp[i];
  }

}

template <class TYPE>
void mergesort(vector<TYPE>& arr, vector<TYPE>& tmp, int start, int end){
  int mid;
  if(start < end)
  {
    mid = (start+end)/2;
    mergesort(arr, tmp, start, mid);
    mergesort(arr, tmp, mid+1, end);
    merge(arr, tmp, start, end);
  }
}

template <class TYPE>
void mergesort(vector<TYPE>& arr){
  //임시 배열을 arr size 만큼만 할당하여 선언한다.
  vector<TYPE> tmp(arr.size());

  mergesort(arr, tmp, 0, arr.size()-1);
}

int main(){
  vector<int> arr;
  srand((unsigned int)time(NULL));

  for(int i=0;i<10;i++)
    arr.push_back(rand()%1000);

  for(int i=0;i<arr.size();i++)
    cout << arr[i] << endl;

  mergesort(arr);
  cout << "After sort:\n" << endl;
  for(int i=0;i<arr.size();i++)
    cout << arr[i] << endl;
  return 0;
}
