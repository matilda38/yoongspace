#include <iostream>

using namespace std;

int d[1001];

int findD(int n){
  if(d[n] > 0) return d[n];

  d[n] = findD(n-1) + findD(n-2);
  d[n] %= 10007;

  return d[n];
}

int main(){
  d[1] = 1;
  d[2] = 2;

  int n, ans;
  cin >> n;
  cout << findD(n);
  return 0;
}
