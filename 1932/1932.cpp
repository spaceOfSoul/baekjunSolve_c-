#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n;
  cin >> n;
  int piramid[n][n];
  int sums[n][n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j <=i;j++){
      cin >> piramid[i][j];
    }
  }
  
  sums[0][0] = piramid[0][0];
  for (int i =1; i<n; i++ ){
    for(int j =0; j<=i; j++){
      if(j == 0)
        sums[i][j] = piramid[i][j] + sums[i-1][j];
      else if(j == i)
        sums[i][j] = piramid[i][j] + sums[i-1][j-1];
      else{
        sums[i][j] = piramid[i][j] + max(sums[i-1][j-1], sums[i-1][j]);
      }
    }
  }

  int result = 0;
  for(int i =0; i < n; i++){
    if(sums[n-1][i] > result)
      result = sums[n-1][i];
  }
  cout << result;
}