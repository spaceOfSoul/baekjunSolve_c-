#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[100];
int cost[100];

int allM;

int dp[10001];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  for(int i=0; i<n; i++)
    cin >> arr[i];
  for(int i=0; i<n; i++){
    cin >> cost[i];
    allM += cost[i];
  }
  for(int i=0; i<n; i++){
    for(int j=allM; j>=cost[i]; j--){
        dp[j] = max(dp[j], dp[j-cost[i]] + arr[i]);
    }
  }
  for(int i = 0; i <= allM; i++){
    if(dp[i]>=m){
      cout << i;
      break;
    }
  }
} 