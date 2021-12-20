#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a,b;
int dp[1001][1001];
string resultStr[1001][1001];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> a;
  cin >> b;

  int aSize = a.size();
  int bSize = b.size();
  for(int i=0; i<aSize; i++){
    for(int j=0; j<bSize; j++){
      if(a[i] == b[j]){
        dp[i+1][j+1] = dp[i][j]+1;
        resultStr[i+1][j+1] += (resultStr[i][j]+a[i]);
      }
      else{
        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        if(resultStr[i+1][j].length() > resultStr[i][j+1].length())
          resultStr[i+1][j+1] = resultStr[i+1][j];
        else
          resultStr[i+1][j+1] = resultStr[i][j+1];
      }
    }
  }
  cout << dp[aSize][bSize] << "\n";
  cout << resultStr[aSize][bSize];
} 