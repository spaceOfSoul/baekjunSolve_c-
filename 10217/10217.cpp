#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<pair<int, int>, int>>> airports;
vector<vector<int>> dist;
int n,m,k;

int djs(){
  priority_queue<pair<pair<int, int>, int>> que;

  dist[1][0] = 0;
  que.push({{0,0},1});

  while(!que.empty()){
    int d = -que.top().first.first;
    int c = -que.top().first.second;
    int now = que.top().second;
    que.pop();

    if(d>dist[now][c] || c > m)
      continue;
    
    if(now == n) return d;
    for(int i =0; i < airports[now].size(); i++){
      int nxt = airports[now][i].second;
      int nxtDist = airports[now][i].first.first + d;
      int nxtCost = airports[now][i].first.second + c;

      if(nxtCost>m) continue;
      if(nxtDist < dist[nxt][nxtCost]){
        dist[nxt][nxtCost] = nxtDist;
        que.push({{-nxtDist,-nxtCost}, nxt});
      }
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  
  int t;
  cin >> t;
  while(t--){
    
    cin >> n >> m >> k;

    airports.assign(n + 1, vector<pair<pair<int, int>, int>>());
    dist.assign(n + 1, vector<int>(m + 1, 999999999));

    int u,v,c,d;
    for(int i=0; i<k; i++){
      cin >> u >> v >> c >> d;
      airports[u].push_back({{d,c},v});
    }

    int result = djs();
    if(result < 0)
      cout << "Poor KCM" << "\n";
    else
      cout << result << "\n";
  }
}