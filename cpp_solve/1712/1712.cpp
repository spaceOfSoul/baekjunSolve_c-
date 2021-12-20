#include <iostream>
using namespace std;

int a,b,c;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> a >> b >> c;
  if(b>=c)
    cout << -1;
  else
    cout << a/(c-b)+1;
} 