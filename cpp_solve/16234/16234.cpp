#include <iostream>
#include <queue>
using namespace std;

int n,l,R;
int arr[50][50];
bool visited[50][50];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int result;

bool bfs(int r, int c){
  queue<pair<int, int>> que;
  queue<pair<int, int>> moveCuntry;
  que.push({r,c});
  moveCuntry.push({r,c});
  visited[r][c] = true;
  int persons = arr[r][c];

  while(!que.empty()){
    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      
      if(0<=nx && nx < n && 0<=ny && ny<n){
        int diff = abs(arr[x][y] - arr[nx][ny]);
        if(!visited[nx][ny] && (l<=diff&&diff<=R)){
          que.push({nx,ny});
          moveCuntry.push({nx,ny});
          visited[nx][ny] = true;
          persons+=arr[nx][ny];
        }
      }
    }
  }
  if(moveCuntry.size()==1)
    return false;
  persons /= moveCuntry.size();
  
  while(!moveCuntry.empty()){
    int x = moveCuntry.front().first;
    int y = moveCuntry.front().second;
    moveCuntry.pop();
    arr[x][y] = persons;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> l >> R;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      cin >> arr[i][j];
  }
  while(true){
    bool isAble = false;
  
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(!visited[i][j]){
          if(!isAble){
            isAble = bfs(i,j);
          }else{
            bfs(i,j);
          }
        }
      }
    }
    if(isAble){
      result++;
      for(int i=0; i<n; i++)
        for(int j=0;j<n; j++)
          visited[i][j] = false;
    }else{
      break;
    }
  }
  cout << result;
} 