#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  unsigned long fibonacciSoo[91] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597};

  for(int i =18; i <= n; i++){
    fibonacciSoo[i] = fibonacciSoo[i-1] + fibonacciSoo[i-2];
  }
  cout << fibonacciSoo[n];
}