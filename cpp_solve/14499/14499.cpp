#include <iostream>
#include <queue>
using namespace std;

int n,m, x,y;
int arr[20][20];
int k;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int dice[6];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);
  cin >> n >> m >> x >> y >> k;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++)
      cin >> arr[i][j];
  }

  int commend;
  queue<int> que;
  while(k--){
    cin >> commend;
    int nx = x+dx[commend-1];
    int ny = y+dy[commend-1];
    //cout << nx << " " << ny << "\n";
    if(0<=nx&&nx<n&&0<=ny&&ny<m){
      switch(commend){
        case 1:
          que.push(dice[0]);
          que.push(dice[1]);
          que.push(dice[5]);
          que.push(dice[2]);
          dice[2] = que.front();que.pop();
          dice[0] = que.front();que.pop();
          dice[1] = que.front();que.pop();
          dice[5] = que.front();que.pop();
          break;
        case 2:
          que.push(dice[0]);
          que.push(dice[2]);
          que.push(dice[5]);
          que.push(dice[1]);
          dice[1] = que.front();que.pop();
          dice[0] = que.front();que.pop();
          dice[2] = que.front();que.pop();
          dice[5] = que.front();que.pop();
          break;
        case 3:
          que.push(dice[0]);
          que.push(dice[3]);
          que.push(dice[5]);
          que.push(dice[4]);
          dice[4] = que.front();que.pop();
          dice[0] = que.front();que.pop();
          dice[3] = que.front();que.pop();
          dice[5] = que.front();que.pop();
          break;
        case 4:
          que.push(dice[0]);
          que.push(dice[4]);
          que.push(dice[5]);
          que.push(dice[3]);
          dice[3] = que.front();que.pop();
          dice[0] = que.front();que.pop();
          dice[4] = que.front();que.pop();
          dice[5] = que.front();que.pop();
          break;
      }
      if(arr[nx][ny]){
        dice[0] = arr[nx][ny];
        arr[nx][ny] = 0;
      }else
        arr[nx][ny] = dice[0];
      x=nx;y=ny;
      cout << dice[5] << "\n";
    }
  }
} 