#include <iostream>
#include <queue>
using namespace std;

int n,k;
int arr[100][100];
bool visited[100][100];
int maxResult;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int r,int c){
  queue<pair<int, int>> que;
  visited[r][c] = true;
  que.push({r,c});
  
  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(0<=nx&&nx<n&&0<=ny&&ny<n&& 
        arr[nx][ny]>k&&!visited[nx][ny]){
        visited[nx][ny] = true;
        que.push({nx,ny});
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
    }
  }

  for(k=0; k<=100; k++){
    int count = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(arr[i][j]>k && !visited[i][j]){
          count++;
          bfs(i,j);
        }
      }
    }
    if(maxResult<count)
      maxResult=count;
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        visited[i][j] = false;
  }
  cout << maxResult;
}