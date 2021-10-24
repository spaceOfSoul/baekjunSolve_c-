#include <iostream>
using namespace std;

int h,m;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> h >> m;
  m -=45;
  if( m < 0){
    m *= -1;
    m = 60 - m;
    h--;
  }
  if(h == -1)
    h = 23;
  cout << h << " " << m;
}