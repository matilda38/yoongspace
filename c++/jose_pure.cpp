#include<iostream>
#include<queue>
using namespace std;
int main(){
  int n , m, i;
  cin >> n;
  cin >> m;

  queue<int> q;
  //initalize
  for(i=0;i<n;i++){
    q.push(i+1);
  }

  n--;
  cout << "<";
  while(n--){
    for(i=0;i<m-1;i++){
      q.push(q.front());
      q.pop();
    }
    cout << q.front();
    q.pop();
    cout << ", ";
  }
  cout << q.front();
  cout << ">\n";

  return 0;
}
