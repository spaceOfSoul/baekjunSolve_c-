#include <iostream>
#include <string>
using namespace std;

bool visited[19][19][4] = {false,}; 
int badukPan[19][19];
int dy[4] = {-1,1,1,0};
int dx[4] = {1,0,1,1};
int count = 0;

void dfs(int y, int x, int d){
  count++;
  visited[y][x][d] = true;
  int nx = x+dx[d];
  int ny = y+dy[d];
  if(0<= nx && 19>nx && 0<= ny && 19>ny)
    if (badukPan[ny][nx] == badukPan[y][x])
      dfs(ny,nx,d);
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  for(int i =0; i < 19; i++){
    for(int j= 0; j<19;j++){
      cin >> badukPan[i][j];
    }
  }

  int winner = 0;
  for(int i = 0; i< 19; i++){
    if(winner!=0)
        break;
    for(int j = 0; j<19;j++){
      if(winner!=0)
        break;
      if(badukPan[j][i] == 0){
        continue;
      }else{
        for(int d=0; d < 4; d++){
          if(visited[j][i][d])
            continue;
          dfs(j,i,d);
          if(count == 5){
            winner = badukPan[j][i];
            cout << winner<<"\n";
            cout << j+1 << " " << i+1;
            break;
          }else count = 0;
        }
      }
    }
  }
  if(winner == 0)
    cout<<0;
}