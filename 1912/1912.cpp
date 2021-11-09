#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000];
int dp[100001];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=0; i< n; i++){
    cin >> arr[i];
    dp[i] = arr[i];
  }
  int result = dp[0];
  for(int i=1; i<n; i++){
    dp[i] = max(dp[i], dp[i-1]+arr[i]);
    if(dp[i] > result){
      result = dp[i];
    }
  }
  cout << result;
} 