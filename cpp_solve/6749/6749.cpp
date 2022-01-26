#include <iostream>
using namespace std;
int a,b;

int main() {
  cin >> a>>b;
  int tmp;
  if(a>b){
    tmp = a;b=a;a=tmp;
  }
  tmp = b-a;
  b+=tmp;
  cout << b;
}