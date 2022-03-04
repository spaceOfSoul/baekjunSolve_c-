#include <iostream>
#include <queue>
#include <stack>
using namespace std;
queue<pair<int,int>> que;

char matrix[8][8];
bool visited[8][8];
int dx[9] = {0,0,1,-1,1,-1,1,-1,0};
int dy[9] = {1,-1,0,0,1,-1,-1,1,0};

void bfs(){
  int size = que.size();
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      visited[i][j] = false;
    }
  }
  while(size--){
    int x = que.front().first;
    int y = que.front().second;
    
    que.pop();
    if(matrix[x][y] == '#')
      continue;

    for(int i=0; i<9; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(0<=nx&&nx<8&&0<=ny&&ny<8&&!visited[nx][ny]){
        if(matrix[nx][ny] == '#')
          continue;
        visited[nx][ny] = true;
        que.push({nx,ny});
      }
    }
  }
}

void wallMove(){
  for(int i=7; i>=0; i--){
    for(int j=7; j>=0; j--){
      if(matrix[i][j] == '#'){
        matrix[i][j] = '.';
        if(i+1<8)
          matrix[i+1][j] = '#';
      }
    }
  }
}

int main() {
 ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      cin >> matrix[i][j];
    }
  }
  que.push({7,0});

  int surviveCount = 8;
  while(surviveCount--){
    bfs();
    if(que.empty()){
      cout << 0;
      return 0;
    }
    wallMove();
  }
  cout << 1;
}