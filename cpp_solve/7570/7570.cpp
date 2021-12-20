#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dp[1000001];
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;

  int a;
  for(int i=0; i<n; i++){
    cin >> a;
    dp[a] = dp[a-1]+1;
    result = max(dp[a], result);
  }
  cout << n-result;
} 