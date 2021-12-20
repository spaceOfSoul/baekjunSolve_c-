#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int t;
int w,h;
char arr[1000][1000];

queue<pair<int, int>> firePos;
int visited[1000][1000];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void fireBfs(int n){
  for(int i=0; i< n; i++){
    int x = firePos.front().first;
    int y = firePos.front().second;
    
    firePos.pop();

    for(int j=0; j<4; j++){
      int nx = x + dx[j];
      int ny = y + dy[j];

      if(0<=nx && nx<h && 0<= ny && ny < w){
        if(arr[nx][ny] == '.'){
          arr[nx][ny] = '*';
          firePos.push({nx, ny});
        }
      }
    }
  }
}

int bfs(int r, int c){
  queue<pair<int, int>> que;
  que.push({r,c});

  while(!que.empty()){
    fireBfs(firePos.size());

    int naviSize = que.size();
    for(int j=0; j< naviSize; j++){
      int x = que.front().first;
      int y = que.front().second;
      que.pop();

      if(x == 0 || x == h-1 || y ==0 || y==w-1)
        return visited[x][y];

      for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0<= nx&&nx<h && 0<=ny && ny<w){
          if(arr[nx][ny] == '.' &&  !visited[nx][ny]){
            visited[nx][ny] = visited[x][y] + 1;
            que.push({nx,ny});
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> t;
  while(t--){
    while(!firePos.empty()) firePos.pop();
    memset(visited, 0, sizeof(visited));

    cin >> w >> h;
    int r,c;
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++){
        cin >> arr[i][j];
        if(arr[i][j] == '@'){
          r=i;c=j;
          visited[r][c] = 1;
        }
        if(arr[i][j] == '*'){
          firePos.push({i,j});
        }
      }
    }
    int result = bfs(r,c);
    if(result == -1)
      cout << "IMPOSSIBLE" << "\n";
    else
      cout << result << "\n";
  }
} 