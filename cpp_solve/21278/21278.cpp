#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int dist[101][101];
int r1,r2;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;

  for(int i=1; i<=n; i++){
    for(int j=1;j<=n; j++){
      if(i==j)
        continue;
      dist[i][j] = 999;
    }
  }

  int a,b;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    dist[a][b] = 1;
    dist[b][a] = 1;
  }

  for(int i=1; i<=n; i++){
    for(int j=1;j<=n; j++){
      for(int k=1; k<=n; k++){
        if(dist[j][k]>dist[j][i]+dist[i][k]){
          dist[j][k] = dist[j][i]+dist[i][k];
        }
      }
    }
  }

  int min_sum = 999999999;
  for(int i=1; i<=n; i++){
    for(int j=i+1; j<=n; j++){
      int sum =0;
      for(int k=1; k<=n; k++){
        sum += min(dist[k][i],dist[k][j])*2;
      }
      if(min_sum > sum){
        min_sum = sum;
        r1=i;r2=j;
      }
    }
  }
  cout << r1 << " " << r2 << " " << min_sum;
}