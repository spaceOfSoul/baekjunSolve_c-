#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int dist[1001][1001];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;

  for(int i=1; i<=n; i++){
    for(int j=1;j<= n; j++){
      if(i==j)
        continue;
      dist[i][j] = 999999999;
    }
  }

  int a,b,c;
  for(int i=0; i <n-1; i++){
    cin >> a >> b >> c;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      for(int k=1; k<=n; k++){
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }
  
  for(int i=0; i<m; i++){
    cin >> a >> b;
    cout << dist[a][b] << "\n";
  }
} 