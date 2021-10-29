#include <iostream>
using namespace std;

int n,m;
int result[7];

void dfs(int deapth){
  if(deapth == m){
    for(int i=0; i<m; i++)
      cout << result[i] << ' ';
    cout << '\n';
    return;
  }

  for(int i = 1; i <= n; i++){
    result[deapth] = i;
    dfs(deapth+1);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  dfs(0);
} 