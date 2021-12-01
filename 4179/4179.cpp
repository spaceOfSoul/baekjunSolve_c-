#include <iostream>
#include <queue>
using namespace std;

char arr[1000][1000];
int visited[1000][1000];
int r,c;
int px, py;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

queue<pair<int, int>> fire;

void fireMultifly(int queSize){
  for(int i=0; i<queSize; i++){
    int x = fire.front().first;
    int y = fire.front().second;
    fire.pop();

    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(0<=nx && nx < r && 0<=ny && ny < c){
        if(arr[nx][ny] == '.'){
          arr[nx][ny] = '*';
          fire.push({nx, ny});
        }
      }
    }
  }
}

int bfs(){
  queue<pair<int, int>> que;
  que.push({px,py});

  while(!que.empty()){
    fireMultifly(fire.size());

    int queSize = que.size();
    for(int i=0; i<queSize; i++){
      int x=que.front().first;
      int y=que.front().second;
      que.pop();

      if(x == 0 || x == r-1 || y==0 || y== c-1)
        return visited[x][y];
      for(int j=0; j<4; j++){
        int nx = x+dx[j];
        int ny = y + dy[j];

        if(0<=nx && nx<r & 0<= ny && ny < c){
          if(arr[nx][ny] == '.' && !visited[nx][ny]){
            visited[nx][ny] = visited[x][y] +1;
            que.push({nx, ny});
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> r >> c;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin >> arr[i][j];
      if(arr[i][j] == 'J'){
        px = i;py = j;
        visited[i][j] = true;
      }else if(arr[i][j] == 'F'){
        fire.push({i,j});
      }
    }
  }

  int result = bfs();
  if (result == -1)
    cout << "IMPOSSIBLE";
  else
    cout << result;
} 