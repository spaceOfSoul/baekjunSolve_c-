#include <iostream>
#include <queue>
using namespace std;

int l,r,c;
int visited[30][30][30];
char arr[30][30][30];

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int escape[3];
int start[3];

int bfs(int sx, int sy, int sz){
  queue<pair<pair<int, int>,int>> que;
  que.push({{sx,sy}, sz});
  visited[sz][sx][sy] = 1;

  while(!que.empty()){
    int x=que.front().first.first;
    int y=que.front().first.second;
    int z = que.front().second;
    que.pop();

    if(x==escape[0] && y==escape[1] && z==escape[2])
      return visited[z][x][y]-1;

    for(int i=0; i<6; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      int nz = z+dz[i];

      if(0<=nx && nx <r && 0<=ny && ny < c && 0<=nz && nz < l){
        if(visited[nz][nx][ny] || arr[nz][nx][ny] == '#')
          continue;
        visited[nz][nx][ny] = visited[z][x][y] + 1;
        que.push({{nx,ny},nz});
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  while(true){
    cin >> l >> r >> c;
    if(l==0 && r==0 && c==0)
      break;
    for(int i=0; i<l; i++){
      for(int j=0; j<r; j++){
        for(int k=0; k<c; k++){
          cin >> arr[i][j][k];
          if(arr[i][j][k] == 'S'){
            start[0] = j;
            start[1] = k;
            start[2] = i;
          }else if(arr[i][j][k] == 'E'){
            escape[0] = j;
            escape[1] = k;
            escape[2] = i;
          }
        }
      }
    }
    int result = bfs(start[0], start[1], start[2]);
    if(result == -1)
      cout << "Trapped!\n";
    else{
      cout << "Escaped in " << result << " minute(s).\n";
    }
    for(int i=0; i<l; i++)
      for(int j=0; j<r; j++)
        for(int k=0; k<c; k++)
          visited[i][j][k] = 0;
  }
} 