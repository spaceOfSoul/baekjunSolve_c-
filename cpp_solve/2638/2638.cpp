#include <iostream>
#include <queue>
using namespace std;

int n,m;
int arr[100][100];
bool visited[100][100];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int result;

void bfs(){
  queue<pair<int, int>> que;
  que.push({0,0});
  visited[0][0] = true;

  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(0<=nx&&nx<n&&0<=ny&&ny<m){
        if(visited[nx][ny] || arr[nx][ny])
          continue;
        que.push({nx,ny});
        visited[nx][ny] = true;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  queue<pair<int,int>> cheese;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
      if(arr[i][j])
        cheese.push({i,j});
    }
  }
  while(!cheese.empty()){
    bfs();
    queue<pair<int,int>> delC;
    int size = cheese.size();
    while(size--){
      int x = cheese.front().first;
      int y = cheese.front().second;
      cheese.pop();

      int reach = 0;
      for(int i=0; i<4; i++){
        int cx = x+dx[i];
        int cy = y+dy[i];
        if(visited[cx][cy])
          reach++;
      }
      if(reach>1){
        delC.push({x,y});
      }else{
        cheese.push({x,y});
      }
    }
    while(!delC.empty()){
      arr[delC.front().first][delC.front().second] = 0;
      delC.pop();
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        visited[i][j] = false;
      }
    }
    result++;
  }
  cout << result;
} 