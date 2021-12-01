#include <iostream>
#include <vector>
using namespace std;

int n, r, q;
vector<int> tree[100001];
bool visited[100001];
int dp[100001];

void dfs(int p){
  dp[p] = 1;
  for(int i:tree[p]){
    if(!dp[i]){
      dfs(i);
      dp[p]+= dp[i];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> r >> q;

  int u,v;
  for(int i=0; i<n-1; i++){
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  dfs(r);

  while(q--){
    cin >> u;
    cout << dp[u] << "\n";
  }
} 