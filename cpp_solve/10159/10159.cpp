#include <iostream>
using namespace std;

int n,m;
bool compare[101][101];
int result[101];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;

  int a,b;
  while(m--){
    cin >> a >> b;
    compare[a][b] = true;
  }

  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      for(int k=1; k<=n; k++)
        if(compare[j][i] && compare[i][k])
          compare[j][k] = true;

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(i==j)
        continue;
      if(!compare[i][j] && !compare[j][i])
        result[i]++;
    }
  }
  for(int i=1; i<=n; i++)
    cout << result[i] << "\n";
} 