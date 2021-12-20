#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a,b;
int dp[1001][1001];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> a;
  cin >> b;
  for(int i=0; i<a.size(); i++){
    for(int j=0; j<b.size(); j++){
      if(a[i] == b[j])
        dp[i+1][j+1] = dp[i][j]+1;
      else
        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
    }
  }
  cout << dp[a.size()][b.size()] << "\n";
} 