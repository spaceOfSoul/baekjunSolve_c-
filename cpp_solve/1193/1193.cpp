#include <iostream>
using namespace std;
int x;
int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> x;
  int sum = 0;
  int row = 1;
  while(x!=1){
    sum += row;
    row++;
    if(sum+row >= x)
      break;
  }
  int namergi = x- sum;
  if(row%2 == 0)
    cout << namergi << '/' << (row+1)-namergi;
  else
    cout << (row+1)-namergi << '/' << namergi;
} 