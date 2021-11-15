#include <iostream>
using namespace std;

int gcd(int a,int b){
  int c = a%b;
  while(c != 0){
    a=b;
    b=c;
    c=a%b;
  }
  return b;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int a, b;
  cin >> a >> b;
  int result = gcd(a,b);
  cout << result << "\n";
  cout << (a*b) / result;
} 