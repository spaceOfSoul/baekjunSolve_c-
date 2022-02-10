#include <iostream>
using namespace std;
int n, result;
int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=1; i<=n; i*=10){
    result+=(n-i+1);
  }
  cout << result;
} 