#include <iostream>
#include <cstring>
using namespace std;

int T;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> T;
  while(T--){
    int n; cin >> n;
    int coins[20];int goal;
    int dp[10001];
    memset(dp,0,sizeof(dp));

    for(int i=0; i<n; i++){
      cin >> coins[i];
    }
    cin >> goal;
    dp[0] = 1;
    for(int i=0; i<n; i++){
      for(int j = coins[i]; j<= goal; j++){
        dp[j] += dp[j-coins[i]];
      }
    }
    cout << dp[goal] << "\n";
  }
} 