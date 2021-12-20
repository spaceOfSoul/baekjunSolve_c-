#include <iostream>
#include <queue>
using namespace std;

int n,m;
int arr[101][101];
bool visited[101][101][4];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};//e1 w2 s3 n4

pair<pair<int, int>, int> robot,goal;

int bfs(){
  queue<pair<pair<pair<int, int>, int>, int>> que;
  que.push({robot,0});
  visited[robot.first.first][robot.first.second][robot.second] = true;
  while(!que.empty()){
    int x = que.front().first.first.first;
    int y = que.front().first.first.second;
    int d = que.front().first.second;
    int commends = que.front().second;
    que.pop();

    if(goal.first.first == x && goal.first.second == y && goal.second == d)
      return commends;
    
    for(int i = 1; i<=3; i++){
      int nx = x + dx[d]*i;
      int ny = y + dy[d] *i;
      if(visited[nx][ny][d])
        continue;
      if(arr[nx][ny] == 1)
        break;
      
      if(0<nx && nx<=m && 0< ny && ny<=n){
        visited[nx][ny][d] = true;
        que.push({{{nx,ny},d},commends+1});
      }
    }
    for(int i=0; i<4; i++){
      if(d == i || visited[x][y][i])
        continue;
      visited[x][y][i] = true;
      if((d==0 && i==1) || (d==1&&i==0)||(d==2&& i==3) || (d==3&&i==2))
        que.push({{{x,y},i},commends+2});
      else
        que.push({{{x,y},i},commends+1});
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> m >> n;

  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++){
      cin >> arr[i][j];
    }
  }
  
  cin >> robot.first.first >> robot.first.second >> robot.second;
  cin >> goal.first.first >> goal.first.second >> goal.second;
  robot.second--;
  goal.second--;
  cout << bfs();
} 