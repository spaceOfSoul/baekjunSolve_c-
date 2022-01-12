#include <iostream>
using namespace std;

int n,k,s;
bool navi[401][401];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> k;

  int a,b;
  while(k--){
    cin >> a >> b;
    navi[a][b] = true;
  }
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      for(int k =1; k<=n; k++)
        if(navi[j][i] && navi[i][k])
          navi[j][k] = true;
      
  cin >> s;
  while(s--){
    cin >> a >> b;
    if(navi[a][b])
      cout << -1;
    else if(navi[b][a])
      cout << 1;
    else{
      cout << 0;
    }
    cout << "\n";
  }
  
} 