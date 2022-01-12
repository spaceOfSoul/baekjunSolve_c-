#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n,k,s,a,b;
int arr[200][200];
vector<pair<int, pair<int,int>>> virus;
queue<pair<int, int>> que;
int sec;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void bfs(){
  while(!que.empty() && sec < s){
    int size = que.size();
    sec++;
    for(int t = 0; t<size; t++){
      int x = que.front().first;
      int y = que.front().second;
      que.pop();

      for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(0<=nx && nx<n && 0<=ny && ny<n){
          if(arr[nx][ny])
            continue;
          arr[nx][ny] = arr[x][y];
          que.push({nx,ny});
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> k;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
      if(arr[i][j] !=0)
        virus.push_back({arr[i][j], {i,j}});
    }
  }
  cin >> s >> a >> b;
  sort(virus.begin(), virus.end());
  for(auto i:virus){
    que.push({i.second.first, i.second.second});
  }
  bfs();
  a--;b--;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
  cout << arr[a][b];
} 