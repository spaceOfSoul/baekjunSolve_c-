#include <iostream>
#include <queue>
#define MAX 999999999
using namespace std;

int n;
char arr[50][50];
int visited[50][50][4];
int result = MAX;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<pair<int, int>,int>> que;
queue<pair<int, int>> door;

void bfs(){
  while(!que.empty()){
    int x = que.front().first.first;
    int y = que.front().first.second;
    int dir = que.front().second;
    que.pop();
    
    int nx = x+dx[dir];
    int ny = y+dy[dir];
    if(0<=nx && nx<n && 0<=ny && ny < n && arr[nx][ny] != '*'){
      if(arr[nx][ny] == '!'){
        for(int i=0; i<4; i++){
          if(dir==i){
            if(visited[nx][ny][dir]>visited[x][y][dir]){
              visited[nx][ny][dir] = visited[x][y][dir];
              que.push({{nx,ny},dir});
            }
          }else{
            if(visited[nx][ny][i]>visited[x][y][dir]+1){
              visited[nx][ny][i] = visited[x][y][dir]+1;
              que.push({{nx,ny},i});
            }
          }
        }
      }else if(arr[nx][ny] == '.'){
        if(visited[nx][ny][dir]>visited[x][y][dir]){
          visited[nx][ny][dir] = visited[x][y][dir];
          que.push({{nx,ny},dir});
        }
      }else if(arr[nx][ny] == '#'){
        if(visited[nx][ny][dir]>visited[x][y][dir])
          visited[nx][ny][dir] = visited[x][y][dir];
      }
    } 
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
      if(arr[i][j] == '#')
        door.push({i,j});
    }
  }

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      for(int k=0;k<4; k++)
        visited[i][j][k] = MAX;

  for(int i=0; i<4; i++){
    visited[door.front().first][door.front().second][i]= 0;
    que.push({{door.front().first,door.front().second},i});
  }
  bfs();
  door.pop();

  for(int i=0; i<4; i++){
    if(visited[door.front().first][door.front().second][i] < result)
      result = visited[door.front().first][door.front().second][i];
  }
  cout << result;
}