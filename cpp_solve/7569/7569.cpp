#include <iostream>
#include <queue>
using namespace std;

int m,n,h;
int arr[100][100][100];

int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};

int result=-1;

typedef struct triple{
  int a,b,c;
}triple;

queue<triple> que;

void bfs(){
  while(!que.empty()){
    triple tmp = que.front();
    int x = tmp.a;
    int y = tmp.b;
    int z = tmp.c;
    que.pop();

    for(int i=0; i<6; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      int nz = z+dz[i];

      if(0<=nx&&nx<h&&0<=ny&&ny<n&&0<=nz&&nz<m&&arr[nx][ny][nz] == 0){
        arr[nx][ny][nz] = arr[x][y][z] +1;
        que.push({nx,ny,nz});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> m >> n >> h;
  for(int i=0; i<h; i++){//
    for(int j=0; j<n; j++){
      for(int k=0; k<m; k++){
        cin >> arr[i][j][k];
        if(arr[i][j][k] == 1)
          que.push({i,j,k});
      }
    }
  }

  bfs();
  for(int i=0; i<h; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<m;k++){
        if(arr[i][j][k] == 0){
          cout << -1;
          return 0;
        }
        if(arr[i][j][k] > result)
          result = arr[i][j][k];
      }
    }
  }
  cout << result-1;
}