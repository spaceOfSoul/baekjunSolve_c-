#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int l,a,b,c,d;
  cin >> l;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  int count = 0;
  while(a>0 || b>0){
    a = a-c;
    b = b-d;
    count++;
  }
  cout << l-count;
}