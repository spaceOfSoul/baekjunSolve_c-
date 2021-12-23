#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[500][500];
int result;
int visited[500][500];
int bigestTake;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int x, int y){
  if(visited[x][y] != 0)
    return visited[x][y];
  visited[x][y] = 1;
  for(int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(0<=nx && nx<n && 0<=ny && ny<n){
      if(arr[nx][ny] > arr[x][y]){
        visited[x][y] = max(dfs(nx,ny)+1, visited[x][y]);
      }
    }
  }
  return visited[x][y];
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      cin >> arr[i][j];
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      result = max(result, dfs(i,j));
    }
  }
  cout << result;
} 