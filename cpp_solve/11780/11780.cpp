#include <iostream>
#include <vector>
using namespace std;

int n,m;
int cost[101][101];
int roads[101][101];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=1; i<= n; i++){
    for(int j=1; j<= n; j++){
      if(i==j) cost[i][j] = 0;
      else cost[i][j] = 999999999;
    }
  }
  cin >> m;
  for(int i=0; i<m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    if(cost[a][b] >c){
      cost[a][b] = c;
      roads[a][b] = b;
    }
  }

  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      for(int k=1; k<=n; k++){
        if(cost[j][k] > cost[j][i] + cost[i][k]){
          cost[j][k] = cost[j][i] + cost[i][k];
          roads[j][k] = roads[j][i];
        }
      }

  for(int i = 1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(cost[i][j] == 999999999)
        cout << 0 << " ";
      else
        cout << cost[i][j] << " ";
    }
    cout << "\n";
  }
  
  for(int i=1; i<= n; i++){
    for(int j=1; j <= n; j++){
      if(i==j || cost[i][j] == 999999999)
        cout << "0";
      else{
        vector<int> result;
        int st = i;
        while(st!= j){
          result.push_back(st);
          st = roads[st][j];
        }
        cout << result.size()+1 << " ";
        for(int k:result)
          cout << k <<" ";
        cout << j;
      }
      cout << "\n";
    }
  }
} 