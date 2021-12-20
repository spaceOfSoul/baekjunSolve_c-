#include <iostream> 
using namespace std;

int n;
int arr[1000];
int dp[1000];
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  int a;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  for(int i=0; i<n; i++){
    dp[i] = arr[i];
    for(int j=0; j<n; j++){
      if(arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
        dp[i] = dp[j] + arr[i];
    }
    if(result < dp[i])
      result = dp[i];
  }
  
  cout << result;
} 