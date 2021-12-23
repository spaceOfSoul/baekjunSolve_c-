#include <iostream>
using namespace std;
int sum,t,a;

int main() {
  t=5;
  while(t--){
    cin >> a;
    if(a<40)
      a=40;
    sum+=a;
  }
  cout << sum/5;
} 