#include <iostream>
using namespace std;

int t;

int gcd(int a, int b){
  while(b){
    int r = a%b;
    a=b;
    b=r;
  }
  return a;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> t;
  while(t--){
    int m,n,x,y;
    cin >> m >> n >> x >> y;
    int lcm = m*n/gcd(m,n);
    int i;
    for(i=x; i <= lcm; i += m){
      int stan;
      if(i%n==0)
        stan = n;
      else
        stan = i%n;
      
      if(stan == y){
        cout << i << "\n";
        break;
      }
    }
    if(i>lcm)
      cout << -1 << "\n";
  }
}