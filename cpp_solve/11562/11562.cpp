#include <iostream>
using namespace std;

int n,m,k;
int navi[251][251];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(i==j)
        continue;
      navi[i][j] = 999999999;
    }
  }

  int a,b,c;
  while(m--){
    cin >> a >> b >> c;
    navi[a][b] = 0;
    if(c==1){
      navi[b][a] = 0;
    }else
      navi[b][a] = 1;
  }

  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      for(int l=1; l<=n; l++){
        if(navi[j][l] > navi[j][i]+navi[i][l])
          navi[j][l] = navi[j][i]+navi[i][l];
      }
  
  cin >> k;
  while(k--){
    cin >> a >> b;
    if(navi[a][b] == 999999999)
      cout << 0;
    else
      cout << navi[a][b];
    cout << "\n";
  }
  
} 