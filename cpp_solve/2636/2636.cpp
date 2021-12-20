#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int r,c;
int arr[100][100];
bool visited[100][100];
int dx[4]= {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int result, count;

int bfs(){
  int cheez =0;
  queue<pair<int, int>> que;
  que.push({0,0});
  visited[0][0] = true;
  
  while(!que.empty()){
    int x = que.front().first;
    int y= que.front().second;
    que.pop();
    
    for(int i=0; i<4; i++){
      int nx = x+dx[i];
      int ny = y+dy[i];

      if(0<= nx && nx<r && 0<= ny && ny <c && !visited[nx][ny]){
        visited[nx][ny] = true;

        if(arr[nx][ny]){
          cheez++;
          arr[nx][ny] = 0;
        }else
          que.push({nx,ny});
      }
    }
  }
  return cheez;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> r >> c;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin >> arr[i][j];
    }
  }
  
  while(true){
    for(int i=0; i<r; i++)
      for(int j=0; j<c; j++)
        visited[i][j] = false;
    int a = bfs();
    
    if(a){
      result = a;
      count++;
    }else{
      break;
    }
  }
  cout << count << "\n" << result << "\n";
} 