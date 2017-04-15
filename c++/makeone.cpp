#include<iostream>

using namespace std;

int d[1000000] = {0, };

int makeone(int n){
  int temp;

  if(n==1) return 0;
  if(d[n] > 0) return d[n];
  d[n] = makeone(n-1) +1;
  if(n%3 == 0) {
    temp = makeone(n/3) + 1;
    if(temp < d[n])
      d[n] = temp;
  }
  if(n%2 == 0){
    temp = makeone(n/2) + 1;
    if(temp < d[n])
      d[n] = temp;
  }
  return d[n];
}

int main(){
  int n;

  cin >> n;
  cout << makeone(n);

  return 0;
}
