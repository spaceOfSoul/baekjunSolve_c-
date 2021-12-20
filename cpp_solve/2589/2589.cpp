#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
char arr[50][50];
int visited[50][50];
int result;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(int r, int c){
  queue<pair<int, int>> que;
  visited[r][c] = 1;
  que.push({r,c});
  int bx=0, by=0;

  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    bx = x;by = y;
    que.pop();

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(0<= nx && nx < n && 0<= ny && ny < m){
        if(visited[nx][ny] || arr[nx][ny] == 'W')
          continue;
        visited[nx][ny] = visited[x][y] +1;
        que.push({nx, ny});
      }
    }
  }
  return visited[bx][by];
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >>m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      cin >> arr[i][j];
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j] != 'W'){
        result = max(result, bfs(i,j));
        for(int k = 0; k<n; k++){
          for(int l=0; l<m; l++)
            visited[k][l] = 0;
        }
      }
    }
  }
  cout << result-1;
} 