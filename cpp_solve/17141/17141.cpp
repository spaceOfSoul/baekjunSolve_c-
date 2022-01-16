#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int arr[50][50];
int result = 999999999;
int space;
bool visited[50][50];
bool choseed[10];
vector<pair<int,int>> site;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(){
  queue<pair<int,int>> que;
  int infectionSize = 0;
  int time = 0;
  for(int i=0; i<site.size(); i++){
    if(choseed[i]){
      que.push({site[i].first, site[i].second});
      visited[site[i].first][site[i].second] = true;
      infectionSize++;
    }
  }
  while(!que.empty()){
    int size = que.size();
    while(size--){
      int x = que.front().first;
      int y = que.front().second;
      que.pop();

      for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<n){
          if(visited[nx][ny] || arr[nx][ny] == 1)
            continue;
          que.push({nx,ny});
          visited[nx][ny] = true;
          infectionSize++;
        }
      }
    }
    time++;
  }
  if(infectionSize == space)
    result = min(result,time-1);
}

void selectSite(int now, int count){
  if(count == m){
    bfs();
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        visited[i][j] = false;
    return;
  }
  for(int i=now; i<site.size(); i++){
    if(choseed[i])
      continue;
    choseed[i] = true;
    selectSite(i, count+1);
    choseed[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  space = n*n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
      if(arr[i][j] ==1)
        space--;
      else if(arr[i][j] == 2)
        site.push_back({i,j});
    }
  }
  selectSite(0, 0);
  if(result == 999999999)
    result = -1;
  cout << result;
} 