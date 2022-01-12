#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
bool dist[501][501];
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  
  int a,b;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    dist[a][b] = true;
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      for(int k=1; k<=n; k++)
        if(dist[j][i]&&dist[i][k])
          dist[j][k] = true;
    }
  }

  for(int i=1; i<=n; i++){
    bool enable = true;
    for(int j=1; j<=n; j++){
      if(i==j)
        continue;
      if(!dist[i][j] && !dist[j][i]){
        enable = false;
        break;
      }
    }
    if(enable)
      result++;
  }
  cout << result;
} 