#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int visited[125][125];
int arr[125][125];
int n;
int t;

int bfs(){
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      visited[i][j] = 999999999;
  queue<pair<int, int>> que;
  que.push({0,0});
  visited[0][0] = arr[0][0];
  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(0<=nx && nx < n && 0<= ny && ny<n){
        if(visited[nx][ny] > visited[x][y] + arr[nx][ny]){
          visited[nx][ny] = visited[x][y] + arr[nx][ny];
          que.push({nx,ny});
        }
      }
    }
  }
  return visited[n-1][n-1];
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  while(true){
    t++;
    cin >> n;
    if(n == 0)
      break;
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        cin >> arr[i][j];
      }
    }
     cout << "Problem " << t << ": " << bfs() << "\n";
  }
} 