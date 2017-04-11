#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
  int n , m, i;
  cin >> n;
  cin >> m;

  int out_size = n;

  vector<int> out;
  out.reserve(out_size);

  queue<int> q;
  //initalize
  for(i=0;i<n;i++){
    q.push(i+1);
  }

  while(n--){
    for(i=0;i<m-1;i++){
      q.push(q.front());
      q.pop();
    }
    out.push_back(q.front());
    q.pop();
  }

  cout << "<";
  for(i=0; i < out_size;i++){
    cout << out.at(i);
    if(i==(out_size-1))
      continue;
    cout << ", ";
  }
  cout << ">";

  return 0;
}
