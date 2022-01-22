#include <iostream>
using namespace std;

int x[3];
int y[3];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  for(int i=0; i<3; i++)
    cin >> x[i] >> y[i];
  int tmp = x[0]*y[1] + x[1]*y[2] + x[2]*y[0];
  tmp -= (y[0]*x[1] + y[1]*x[2] + y[2]*x[0]);

  if(tmp > 0)
    cout << 1;
  else if(tmp<0)
    cout << -1;
  else
    cout << 0;
} 