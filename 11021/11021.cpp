#include <iostream>
using namespace std;
int t;
int main() {
  cin >> t;
  for(int i=1; i<=t; i++){
    int a,b;
    cin >> a >> b;
    cout <<"Case #" << i << ": " << a+b << "\n";
  }
} 