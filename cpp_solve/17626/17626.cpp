#include <iostream>
#include <algorithm>
using namespace std;

int dpCach[50001]={0,1,2,3,1};

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  cin >> n;

  for(int i=4; i<= n; i++){
    int stan = 999999;
    for(int j = 1; j*j <=i; j++ ){
      stan = min(stan, dpCach[i-j*j]);
    }
    dpCach[i] = stan+1;
  }
  cout<<dpCach[n];
}