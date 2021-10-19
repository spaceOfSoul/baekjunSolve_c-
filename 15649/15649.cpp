#include <iostream>
#include <vector>
using namespace std;

bool visited[8] = {false,};
vector<int> result;

void dfs(int n, int m, int length){

  if(length == m){
    for (int i = 0; i < m; i++){
      cout << result[i] << " ";
    }
    cout << "\n";
  }

  for(int i =0; i < n; i++){
    if (visited[i] == true)
      continue;

    visited[i] = true;
    result.push_back(i+1);

    dfs(n,m,length+1);

    result.pop_back();
    visited[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n,m;
  cin >> n >> m;
  dfs(n,m,0);
}