#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, x;
vector<pair<int, int>> graph[1001];
int dist[1001];

void djs(int s){
  for(int i=1; i<= n; i++)
    dist[i] = 999999999;

  priority_queue<pair<int, int>> que; 
  que.push({0,s});
  dist[s] =0;
  while(!que.empty()){
    int d=-que.top().first;
    int v = que.top().second;
    que.pop();
    if(dist[v] < d)
      continue;
    for(pair<int, int> i:graph[v]){
      int cost = d + i.second;
      if(cost < dist[i.first]){
        dist[i.first] = cost;
        que.push({-cost, i.first});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m >> x;

  int onengil[1001];

  for(int i=0; i<m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    graph[a].push_back({b,c});
  }
  djs(x);
  for(int i=1; i<=n; i++)
    onengil[i] = dist[i];
  
  int result = 0;
  for(int i=1; i<= n; i++){
    if(i==x)
      continue;
    djs(i);
    result = max(result, onengil[i]+dist[x]);
  }
  cout << result;
}