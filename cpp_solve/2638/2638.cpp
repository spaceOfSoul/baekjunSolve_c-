#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
vector<int> graph[20001];
vector<int> result;
int lenth=1;
int visited[20001];

void bfs(){
  queue<int> que;
  que.push(1);
  visited[1] = 1;

  while(!que.empty()){
    int now = que.front();
    que.pop();
    for(int i:graph[now]){
      if(visited[i])
        continue;
      visited[i] = visited[now] +1;
      if(visited[i] > lenth){
        result.clear();
        result.push_back(i);
        lenth = visited[i];
      }else if(visited[i] == lenth){
        result.push_back(i);
      }
      que.push(i);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;

  int a,b;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  bfs();
  sort(result.begin(), result.end());
  cout << result[0] << " " << visited[result[0]]-1 << " " << result.size();
} 