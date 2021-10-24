#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  cin >> n;
  int min = 0;
  int max = 0;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    if(i==0){
      min = a;max = a;
    }
    if(a > max)
      max = a;
    else if(a<min)
      min = a;
  }
  cout << min << " " << max;
}