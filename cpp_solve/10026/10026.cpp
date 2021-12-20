#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n;
string image[100];
bool graph[100][100];
bool visited[2][100][100];
int result[2];

int bfs(int r, int c){
  char stan = image[r][c];
  int dx[4] = {1,-1,0,0};
  int dy[4] = {0,0,1,-1};
  queue<pair<int,int>> que;
  que.push({r,c});

  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    que.pop();
    visited[1][x][y] = true;

    for(int i = 0; i <4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(0<=nx&&nx<n&&0<=ny&&ny<n){
        if(!visited[1][nx][ny] && image[nx][ny] == stan){
          visited[1][nx][ny] = true;
          que.push({nx,ny});
        }
      }
    }
  }
  return 1;
}

int grayBfs(int r, int c){
  bool stan = graph[r][c];
  int dx[4] = {1,-1,0,0};
  int dy[4] = {0,0,1,-1};
  queue<pair<int,int>> que;
  que.push({r,c});

  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    que.pop();
    visited[0][x][y] = true;

    for(int i = 0; i <4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(0<=nx&&nx<n&&0<=ny&&ny<n){
        if(!visited[0][nx][ny] && graph[nx][ny] == stan){
          visited[0][nx][ny] = true;
          que.push({nx,ny});
        }
      }
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> image[i];
  
  for(int i =0; i<n; i++){
    for (int j = 0; j <n; j++){
      if(!visited[1][i][j])
        result[1] += bfs(i,j);
      if(image[i][j] != 'B')
        graph[i][j] = true;
    }
  }
  for(int i =0; i<n; i++){
    for(int j=0;j<n;j++){
      if(!visited[0][i][j])
        result[0] += grayBfs(i, j);
    }
  }
  cout << result[1] << " " << result[0];
}