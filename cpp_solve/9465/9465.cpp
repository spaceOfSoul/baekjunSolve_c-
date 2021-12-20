#include <iostream>
#include <algorithm>
using namespace std;

int n, t;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> t;
  while(t--){
    cin >> n;
    int arr[2][100000];
    int dp[2][100001];
    for(int i=0; i<2; i++){
      for(int j=0; j<n; j++){
        cin >> arr[i][j];
      }
    }

    dp[0][1] = arr[0][0];
    dp[1][1] = arr[1][0];
    for(int i=2;i<=n; i++){
      dp[0][i] = max(dp[1][i-1], dp[1][i-2])+arr[0][i-1];
      dp[1][i] = max(dp[0][i-1], dp[0][i-2])+arr[1][i-1];
    }
    cout << max(dp[0][n],dp[1][n])<<"\n";
  }
} 