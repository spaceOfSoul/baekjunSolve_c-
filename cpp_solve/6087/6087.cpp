#include <iostream>
#include <queue>
#define MAX 999999999
using namespace std;

int w,h;
char arr[100][100];
int visited[100][100][4];
queue<pair<pair<int,int>,int>> que;
queue<pair<int, int>> c;
int result = MAX;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(){
  while(!que.empty()){
    int x = que.front().first.first;
    int y = que.front().first.second;
    int dir = que.front().second;
    que.pop();

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      bool place = false;
      if(0<=nx && nx<h && 0<=ny && ny < w && arr[nx][ny] != '*'){
        if(dir != i && visited[nx][ny][i]>visited[x][y][dir]+1){
          visited[nx][ny][i] = visited[x][y][dir]+1;
          que.push({{nx,ny},i});
        }else if(dir==i && visited[nx][ny][i]>visited[x][y][i]){
          visited[nx][ny][i] = visited[x][y][i];
          que.push({{nx,ny},i});
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> w >> h;

  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 'C'){
        c.push({i,j});
      }
    }  
  }
  
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++)
      for(int k=0;k<4; k++)
        visited[i][j][k] = MAX;
  }
  for(int i=0; i<4; i++){
    visited[c.front().first][c.front().second][i]= 0;
    que.push({{c.front().first,c.front().second},i});
  }
  bfs();
  c.pop();
  
  for(int i=0; i<4; i++){
    if(visited[c.front().first][c.front().second][i] < result)
      result = visited[c.front().first][c.front().second][i];
  }
  cout << result;
} 