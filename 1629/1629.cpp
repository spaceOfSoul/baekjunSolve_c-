#include <iostream>
#include <cmath>
using namespace std;

long long a,b,c;

long long moltisios(long long a, long long b){
  if(b == 1)
    return a%c;
  if(b%2 == 0){
    long long r = moltisios(a, b/2);
    return (r*r) % c;
  }else{
    return (a* moltisios(a, b-1)) % c;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> a >> b >> c;
  cout << moltisios(a,b);
} 