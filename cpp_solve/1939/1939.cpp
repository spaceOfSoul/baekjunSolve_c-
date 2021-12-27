#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int f1,f2;
vector<pair<int, int>> graph[100001];
bool visited[100001];

bool bfs(int weight){
  queue<int> que;
  que.push(f1);
  visited[f1]= true;

  while(!que.empty()){
    int now = que.front();
    que.pop();

    if(now == f2){
      return true;
    }

    for(auto i:graph[now]){
      if(!visited[i.first] && weight <= i.second){
        que.push(i.first);
        visited[i.first] = true;
      }
    }
  }
  return false;
}


int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;
  int a,b,c;
  for(int i=0; i<m; i++){
    cin >> a >> b >> c;
    graph[a].push_back({b,c});
    graph[b].push_back({a,c});
  }
  cin >> f1 >> f2;

  int left = 1;
  int right = 1000000000;
  while(left<=right){
    int mid = (left+right)/2;
    if(bfs(mid)){
      left = mid+1;
    }else{
      right = mid-1;
    }
    for(int i=1; i<=n; i++)
      visited[i] = false;
  }
  cout << right;
} 