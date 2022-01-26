#include <iostream>
#include <queue>
using namespace std;

char arr[12][6];
bool visited[12][6];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int result;

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

      if(0<=nx&&nx<12&&0<=ny&&ny<6){
        if(visited[nx][ny]||arr[nx][ny] != arr[r][c])
          continue;
        visited[nx][ny] = true;
        que.push({nx,ny});
      }
    }
  }
  if(del.size()>=4){
    while(!del.empty()){
      int x = del.front().first;
      int y = del.front().second;
      del.pop();

      arr[x][y] = '.';
    }
    return true;
  }
  return false;
}

void puyoDown(int r, int c){
  while(true){
    int ny = r+1;
    if(ny<12 && arr[ny][c] == '.'){
      arr[ny][c] = arr[r][c];
      arr[r][c] = '.';
      r=ny;
    }else{
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  for(int i=0;i<12; i++){
    for(int j=0; j<6; j++)
      cin >> arr[i][j];
  }
  bool bomb = true;
  while(bomb){
    bomb = false;
    for(int i=0; i<12; i++){
      for(int j=0; j<6; j++){
        if(arr[i][j] !='.' && !visited[i][j]){
          if(bfs(i,j))
            if(!bomb)
             bomb = true;
        }
      }
    }
    if(bomb){
      result++;
      for(int i=11; i>=0; i--){
        for(int j=0; j <6; j++){
          visited[i][j] = false;
          if(arr[i][j] != '.')
            puyoDown(i,j);
        }
      }
    }
  }
  cout << result;
} 