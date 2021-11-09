#include <iostream>
using namespace std;

int n;

int main() {
  cin >> n;
  for(int i=1; i<= n; i++){
    int a,b;
    cin >> a >> b;
    cout << "Case #"<<i<<": "<< a << " + "<<b <<" = " <<a+b<<"\n";
  }
} 