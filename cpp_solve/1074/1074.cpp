#include <iostream>
#include <cmath>
using namespace std;

int result = 0;

void whatsTere(int r, int c, int n){
  if(n == 1)
    return;

  if(r <= n / 2){
    if(c <= n / 2){
      whatsTere(r, c, n/2);
      return;
    }else{
      result += (n/2)*(n/2) * 1;
      if(c - n/2 >= 1){
        c = c - n/2;
      }
      whatsTere(r, c, n/2);
      return;
    }
  }else{
    if(c <= n / 2){
      result += (n/2)*(n/2) * 2;

      if(r - n/2 >= 1){
        r = r - n/2;
      }
      whatsTere(r, c, n/2);
      return;
    }else{
      result += (n/2)*(n/2) * 3;

      if(r - n/2 >= 1){
        r = r - n/2;
      }
      if(c - n/2 >= 1){
        c = c - n/2;
      }
      whatsTere(r, c, n/2);
      return;
    }
  }
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
	ios::sync_with_stdio(false);

  int r,c,n;
  cin >> n >> r >> c;

  n = pow(2,n);
  whatsTere(r+1,c+1,n);
  cout << result;
}