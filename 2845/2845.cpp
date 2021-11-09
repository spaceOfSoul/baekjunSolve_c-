#include <iostream>
using namespace std;
int l,p;

int main() {
  cin >> l >> p;
  int a;
  for(int i =0; i<5; i++){
    cin >> a;
    cout << a-l*p << " ";
  }
} 