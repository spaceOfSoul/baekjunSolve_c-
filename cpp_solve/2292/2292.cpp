#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int a;
  cin >> a;
  int result = 1;
  int stan = 1;
  while(a>stan){
    stan += 6*result;
    result++;
  }
  cout << result;
} 