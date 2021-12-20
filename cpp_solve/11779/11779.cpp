#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int n,m,start, goal;
vector<pair<int, int>> graph[1001];
int dist[1001];
int navi[1001];

void djs(int v){
  for(int i=1; i<= n; i++)
    dist[i] = 999999999;

  priority_queue<pair<int, int>> que;
  dist[v] = 0;
  que.push({0,v});

  while(!que.empty()){
    int cost = -que.top().first;
    int now = que.top().second;
    que.pop();
    if(dist[now] < cost)
      continue;
    
    for(pair<int, int> i : graph[now]){
      int nxCost = i.second + cost;
      if(nxCost < dist[i.first]){
        dist[i.first] = nxCost;
        que.push({-nxCost, i.first});
        navi[i.first] = now;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  cin >> m;
  for(int i=0; i<m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    graph[a].push_back({b,c});
  }
  cin >> start >> goal;
  djs(start);

  cout << dist[goal] << "\n";

  stack<int> route;
  int st = goal;
  while(st){
    route.push(st);
    st = navi[st];
  }
  cout << route.size() << "\n";
  while(!route.empty()){
    cout << route.top() << " ";
    route.pop();
  }
} 