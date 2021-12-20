#include <iostream>
using namespace std;

int a,b,c,d;

int main() {
  cin >> a >> b >> c >> d;
  int time = a*60*60 + b*60 +c + d;
  time %= 86400;
  a = time/3600;
  cout << a << " ";
  time -=(a*3600);
  b = time/60;
  cout << b << " ";
  time -= (b*60);
  cout << time;
} 