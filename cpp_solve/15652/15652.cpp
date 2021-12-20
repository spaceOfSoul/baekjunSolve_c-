#include <iostream>
using namespace std;

int n,m;
int arr[8];

void dfs(int deapth,int before){
  if(deapth == m){
    for(int i=0; i< m; i++)
      cout << arr[i] << ' ';
    cout << "\n";
    return;
  }
  
    for(int i = before; i<=n; i++){
      arr[deapth] = i;
      dfs(deapth+1,i);
    }
  
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;
  dfs(0,1);
} 