#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int dp[1000];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;

  int a;
  for(int i=0; i<n; i++){
    cin >> arr[i];
    dp[i] = 1;
  }
  int result = 1;
  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
      if(arr[j] > arr[i]){
        dp[i] = max(dp[i], dp[j] +1);
      }
    }
    result= max(result, dp[i]);
  }
  cout << result;
} 