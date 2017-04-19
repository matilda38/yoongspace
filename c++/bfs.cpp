#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cstdio>

using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int x){
  check[x] = true;
  cout << x << " ";
  for(int i=0;i<a[x].size();i++){
    int y = a[x][i];
    if(check[y] == false){
      dfs(y);
    }
  }
}
//안 방문했으면 큐에 넣는거야
void bfs(int x){
  memset(check, false, sizeof(check));
  queue<int> q;
  check[x] = true;
  q.push(x);
  while(!q.empty()){
    int node = q.front();
    q.pop();
    cout << node << " ";
    for(int i=0;i<a[node].size();i++){
      int y= a[node][i];
      if(check[y] == false){
        check[y] = true;
        q.push(y);
      }
    }
  }
}
int main(){
  int n,m,start;
  cin >> n >> m >> start;

  for(int i=0;i<m;i++){
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for(int i=1;i<=n;i++){
    sort(a[i].begin(), a[i].end());
  }
  dfs(start);
  cout << "\n";
  bfs(start);
}
