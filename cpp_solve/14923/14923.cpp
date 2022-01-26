#include <iostream>
#include <queue>
using namespace std;

int n, m, hx, hy, ex, ey;
int arr[1000][1000];
int visited[1000][1000][2];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int result = -1;

void bfs(){
  queue<pair<pair<int, int>,bool>> que;
  que.push({{hx,hy},false});
  visited[hx][hy][0] = 1;

  while(!que.empty()){
    int x = que.front().first.first;
    int y = que.front().first.second;
    int breaking = que.front().second;
    que.pop();

    if(x==ex&&y==ey){
      result = visited[x][y][breaking]-1;
      break;
    }

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(0<=nx&&nx<n&&0<=ny&&ny<m){
        if(!arr[nx][ny]&&!visited[nx][ny][breaking]){
          visited[nx][ny][breaking] = visited[x][y][breaking]+1;
          que.push({{nx,ny},breaking});
        }else if(!breaking&& arr[nx][ny] && !visited[nx][ny][1]){
          que.push({{nx,ny},true});
          visited[nx][ny][1] = visited[x][y][0]+1;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  cin >> hx >> hy >> ex >> ey;
  hx--;hy--;ex--;ey--;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
    }
  }
  bfs();
  cout << result;
} 