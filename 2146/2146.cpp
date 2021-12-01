#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[100][100];
int n;

int dx[4] ={1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<queue<pair<int, int>>> islands;
int visited[100][100];

int result = 999999999;

void paintLand(int x, int y, int paint){
  queue<pair<int, int>> que;
  queue<pair<int, int>> is;
  que.push({x,y});
  is.push({x,y});
  arr[x][y] = paint;
  while(!que.empty()){
    int nowx = que.front().first;
    int nowy = que.front().second;
    que.pop();

    for(int i=0; i<4; i++){
      int nx = nowx+dx[i];
      int ny = nowy+dy[i];
      if(0<=nx && nx < n && 0<= ny && ny < n){
        if(arr[nx][ny] == 0 || arr[nx][ny] == paint)
          continue;
        arr[nx][ny] = paint;
        is.push({nx,ny});
        que.push({nx,ny});
      }
    }
  }
  islands.push(is);
}

void bfs(queue<pair<int, int>> a, int land){
  while(!a.empty()){
    int x = a.front().first;
    int y = a.front().second;
    a.pop();

    if(arr[x][y] != 0 && arr[x][y] != land){
      result = min(result, visited[x][y]);
      return;
    }

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y + dy[i];
      if(0<=nx && nx<n && 0<=ny && ny<n){
        if(visited[nx][ny] || arr[nx][ny] == land)
          continue;
        visited[nx][ny] = visited[x][y] + 1;
        a.push({nx,ny});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      cin >> arr[i][j];
  }

  int paint = -1;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(arr[i][j] == 1){
        paintLand(i, j, paint);
        paint--;
      }
    }
  }

  for(int i=-1; i>paint; i--){
    bfs(islands.front(), i);
    islands.pop();
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        visited[j][k] = 0;
      }
    }
  }
  cout << result-1;
} 