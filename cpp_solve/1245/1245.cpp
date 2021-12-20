#include <iostream>
#include <queue>
using namespace std;

int n,m;
int arr[100][70];
int result;

bool visited[100][70];
int dx[8] = {0,0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,1,-1,-1,1};

void bfs(int i, int j){
  queue<pair<int, int>> que;
  que.push({i,j});
  visited[i][j] = true;
  int h = arr[i][j];
  bool peek = true;

  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for(int i=0; i<8; i++){
      int nx = x+dx[i];
      int ny = y+ dy[i];

      if(0<=nx && nx < n && 0<= ny && ny <m){
        if(arr[nx][ny] > h)
          peek = false;
        else if(!visited[nx][ny] && arr[nx][ny] == h){
          visited[nx][ny] = true;
          que.push({nx,ny});
        }
      }
    }
  }
  if(peek)result++;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      cin >> arr[i][j];
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(!visited[i][j])
        bfs(i,j);
    }
  }
  cout << result;
} 