#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> graph[50];
int cut;

int dfs(int v){
  int leap = 0;
  for(int i=0; i< graph[v].size(); i++){
    if(graph[v][i] == cut)
      continue;
    leap+= dfs(graph[v][i]);
  }
  if(leap==0)
    return 1;
  return leap;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  int root;
  for(int i=0; i<n; i++){
    int c; cin >> c;
    if(c == -1){
      root =i;
      continue;
    }
    graph[c].push_back(i);
  }
  
  cin >> cut;
  if (cut != root)
    cout << dfs(root);
  else
    cout << 0;
} 