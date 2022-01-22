#include <iostream>
using namespace std;

int n,m;
int arr[500][500];
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  cin >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      arr[i][j] = 999999999;
      if(i==j)
        arr[i][j] = 0;
    }
  }
  int a,b;
  while(m--){
    cin >> a >> b;
    a--;b--;
    arr[a][b] = 1;
    arr[b][a] = 1;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        if(arr[j][k]>arr[j][i]+arr[i][k])
          arr[j][k] = arr[j][i]+arr[i][k];
      }
    }
  }
  for(int i=1; i<n; i++){
    if(arr[0][i]<=2)
      result++;
  }
  cout << result;
} 