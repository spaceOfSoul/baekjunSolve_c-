#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k,x;
vector<int> graph[300001];
int visited[300001];
vector<int> result;

void bfs(){
  visited[x] = 1;
  queue<int> que;
  que.push(x);

  while(!que.empty()){
    int now = que.front();
    que.pop();

    if(visited[now]-1 == k)
      result.push_back(now);

    for(int i:graph[now]){
      if(visited[i])
        continue;
      visited[i] = visited[now]+1;
      que.push(i);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m >> k >> x;

  int a,b;
  while(m--){
    cin >> a >> b;
    graph[a].push_back(b);
  }
  bfs();
  if(result.empty()){
    cout << -1;
    return 0;
  }
  sort(result.begin(), result.end());
  for(int i:result)
    cout << i << "\n";
} 