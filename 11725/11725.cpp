#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100000];
int parents[100000];
bool visited[100000];

void dfs(int v){
  visited[v] = true;
  for(int i = 0; i < graph[v].size();i++){
    if(!visited[graph[v][i]]){
      parents[graph[v][i]] = v;
      dfs(graph[v][i]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  cin >> n;

  for(int i = 0; i < n-1; i++){
    int a,b;
    cin >> a >> b;
    graph[a-1].push_back(b-1);
    graph[b-1].push_back(a-1);
  }
  dfs(0);
  for(int i = 1; i<n; i++){
    cout<< parents[i]+1 << "\n";
  }
}