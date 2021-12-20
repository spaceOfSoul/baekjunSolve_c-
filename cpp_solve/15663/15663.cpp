#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int arr[8];
int result[8];
bool visited[8];

void dfs(int deapth){
  if(deapth == m){
    for(int i=0; i< m; i++){
      cout << result[i] << " ";
    }
    cout << "\n";
    return;
  }

  int notThis = 0;
  for(int i = 0; i< n; i++){
    if(visited[i]||arr[i]==notThis)
      continue;
    visited[i] = true;
    notThis=result[deapth]=arr[i];
    dfs(deapth+1);
    visited[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;

  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  sort(arr, arr+n);
  dfs(0);
} 