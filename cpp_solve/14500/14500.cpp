#include <iostream>
using namespace std;

int n,m;
int arr[500][500];
bool visited[500][500];
int result;

void dfs(int r, int c, int deapth,int sum){
  sum += arr[r][c];
  visited[r][c] = true;
  if(deapth == 4){
    if(sum > result)
      result =sum;
    return;
  }

  int dx[4] = {1,-1,0,0};
  int dy[4] = {0,0,1,-1};

  for(int i=0; i< 4; i++){
    int nx = r+dx[i];
    int ny = c+dy[i];
    if(0<=nx && nx < n && 0 <= ny && ny < m){
      if(!visited[nx][ny]){
        dfs(nx,ny,deapth+1, sum);
        visited[nx][ny] = false;
      }
    }
  }
  visited[r][c] = false;
}

void triangle(int r, int c){
  //Oo
  //oo
  //oo
  if(r+2<n && c+1 < m){
    int sum = arr[r+1][c]+arr[r][c+1]+arr[r+1][c+1]+arr[r+2][c+1];
    if(sum > result)
      result = sum;

    sum = arr[r][c] + arr[r+1][c] + arr[r+1][c+1] + arr[r+2][c];
    if(sum>result)
      result = sum;
  }
  //Ooo
  //ooo
  if(r+1<n && c+2<m){
    int sum = arr[r+1][c]+arr[r][c+1]+arr[r+1][c+1]+arr[r+1][c+2];
    if(sum > result)
      result = sum;

    sum = arr[r][c] + arr[r][c+1] + arr[r+1][c+1] + arr[r][c+2];
    if(sum>result)
      result = sum;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  for(int i =0; i< n; i++){
    for(int j =0; j<m; j++){
      cin >> arr[i][j];
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      dfs(i,j,1,0);
      triangle(i,j);
    }
  }

  cout << result;
} 