#include <iostream>
#include <queue>
using namespace std;

int visited[100];

void bfs(int *gameMap, int* visited){
  queue<int> que;
  que.push(0);

  while(!que.empty()){
    int now = que.front();
    que.pop();
    for(int i = 1; i <= 6; i++){
      int nxt = now + i;
      if(nxt>99)
        continue;
      if (gameMap[nxt] != -1)
        nxt = gameMap[nxt];
      if (visited[nxt] == 0){
        visited[nxt] = visited[now] + 1;
        que.push(nxt);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int gameMap[100];
  for(int i = 0; i<100; i++){
    gameMap[i] = -1;
  }
  int n,m;
  cin >> n >> m;
  for(int i = 0;i <n+m;i++){
    int x,y;
    cin >> x >> y;
    gameMap[x-1] = y-1;
  }
  bfs(gameMap,visited);
  cout << visited[99];
}