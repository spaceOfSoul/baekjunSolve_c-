#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,m;
vector<int> graph[101];
int a,b;
int visited[101];

void bfs(){
  queue<int> que;
  que.push(a);
  visited[a] = 0;
  while(!que.empty()){
    int now = que.front();
    que.pop();

    if(now == b)
      return;

    for(int i=0; i< graph[now].size(); i++){
      if(visited[graph[now][i]] != -1)
        continue;
      visited[graph[now][i]] = visited[now] + 1;
      que.push(graph[now][i]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  cin >> a >> b;
  cin >> m;
  for(int i=0; i<m; i++){
    int x,y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  memset(visited, -1, sizeof(visited));
  bfs();
  cout << visited[b];
} 