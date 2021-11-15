#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,m;
vector<int> graph[10001];
bool visited[10001];
int count;
int maxVal;
vector<int> result;

void dfs(int v){
  visited[v] = true;
  for(int i=0; i< graph[v].size(); i++){
    if(visited[graph[v][i]])
      continue;
    visited[graph[v][i]] = true;
    count++;
    dfs(graph[v][i]);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  for(int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    graph[b].push_back(a);
  }
  for(int i=1; i<=n; i++){
    dfs(i);
    
    if(count > maxVal){
      maxVal = count;
      result.clear();
    }
    if(count==maxVal)
      result.push_back(i);
    count = 0;
    memset(visited, false, sizeof(visited));
  }
  for(int i=0; i< result.size(); i++){
    cout << result[i] << " ";
  }
} 