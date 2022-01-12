#include <iostream>
#include <cstring>
using namespace std;

int n,m;
bool table[100][100];
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;

  int a,b;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    table[a][b] = true;
  }

  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      for(int k=1; k<=n; k++)
        if(table[j][i] && table[i][k])
          table[j][k] = true;
        
  for(int i=1; i<=n; i++){
    int light = 0;
    int heavy = 0;
    for(int j=1; j<=n; j++){
      if(table[i][j])
        light++;
      if(table[j][i])
        heavy++;
    }
    
    if(light>n/2 || heavy > n/2){
      result++;
    }
  }
  cout << result;
} 