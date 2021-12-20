#include <iostream>
using namespace std;

int stair[300];
int c[300];
int n;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> stair[i];
  
  c[0] = stair[0];
  c[1] = max(stair[1],stair[0]+stair[1]);
  c[2] = max(stair[0]+stair[2], stair[1]+stair[2]);

  for(int i=3; i<n; i++){
    c[i] = max(stair[i] + c[i-2], stair[i] + stair[i-1] + c[i-3]);
  }
  cout << c[n-1];
}