#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n,m,k,a,b,c;
int arr[101][101];
int friends[100];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> t;
  while(t--){
    cin >> n >>m;
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(i==j)
          continue;
        arr[i][j] = 999999999;
      }
    }
    for(int i=0; i<m; i++){
      cin >> a >> b >> c;
      arr[a][b] = min(arr[a][b],c);
      arr[b][a] = min(arr[b][a],c);
    }

    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        for(int l = 1; l<=n; l++){
          arr[j][l] = min(arr[j][l], arr[j][i]+arr[i][l]);
        }
      }
    }
    
    cin >> k;
    for(int i=0; i<k; i++){
      cin >> friends[i];
    }

    int sum=0;
    int dist = 999999999;
    int result;
    for(int i=1; i<=n; i++){
      for(int j=0; j<k; j++){
        sum+=arr[friends[j]][i];
      }
      if(sum < dist){
        dist = sum;
        result = i;
      }
      sum =0;
    }
    cout << result << "\n";
  }
} 