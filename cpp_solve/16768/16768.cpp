#include <iostream>
#include <queue>
using namespace std;

int n,k;
char arr[100][10];
bool visited[100][10];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool bfs(int r,int c){
  visited[r][c] = true;
  queue<pair<int, int>> que;
  queue<pair<int, int>> del;
  que.push({r,c});

  while(!que.empty()){
    int x = que.front().first;
    int y=que.front().second;
    que.pop();

    del.push({x,y});
    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(0<=nx&&nx<n&&0<=ny&&ny<10){
        if(visited[nx][ny]||arr[nx][ny] != arr[r][c])
          continue;
        visited[nx][ny] = true;
        que.push({nx,ny});
      }
    }
  }
  if(del.size()>=k){
    while(!del.empty()){
      int x = del.front().first;
      int y = del.front().second;
      del.pop();

      arr[x][y] = '0';
    }
    return true;
  }
  return false;
}

void puyoDown(int r, int c){
  while(true){
    int ny = r+1;
    if(ny<n && arr[ny][c]=='0'){
      arr[ny][c] = arr[r][c];
      arr[r][c] = '0';
      r=ny;
    }else{
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> k;
  for(int i=0; i<n; i++){
    for(int j=0; j<10; j++){
      cin >> arr[i][j];
    }
  }

  bool bomb = true;
  while(bomb){
    bomb = false;
    for(int i=0; i<n; i++){
      for(int j=0; j<10; j++){
        if(arr[i][j]!='0' && !visited[i][j]){
          if(bfs(i,j))
            if(!bomb)
             bomb = true;
        }
      }
    }
    if(bomb){
      for(int i=n-1; i>=0; i--){
        for(int j=0; j <10; j++){
          visited[i][j] = false;
          if(arr[i][j] != '0')
            puyoDown(i,j);
        }
      }
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<10; j++)
      cout << arr[i][j];
    cout << "\n";
  }
} 