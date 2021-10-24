#include <iostream>
using namespace std;

int main() {
  int n,x;
  cin >> n >> x;
  for(int i = 0; i <n; i++){
    int q;
    cin >> q;
    if(q<x)
      cout << q << "\n";
  }
}