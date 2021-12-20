#include <iostream>
#include <vector>
using namespace std;

int r,c;
char arr[20][20];
bool visited[26];
int result;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int a, int b, int count){
  if(result<count)
    result = count;
  for(int i=0; i<4; i++){
    int nx = a+dx[i];
    int ny = b+ dy[i];

    if(0<=nx && nx<r && 0<= ny && ny<c){
      if(visited[arr[nx][ny] - 'A'])
        continue;
      visited[arr[nx][ny] - 'A'] = true;
      dfs(nx, ny, count+1);
      visited[arr[nx][ny] - 'A'] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> r >> c;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++)
      cin >> arr[i][j];
  }
  visited[arr[0][0]-'A'] = true;
  dfs(0,0,1);
  cout << result;
} 