#include <iostream>
using namespace std;

int n;

void star(int a, int b, int n){
  if(a/n % 3==1 && b/n % 3 ==1)
    cout << " ";
  else if(n/3 == 0)
    cout << "*";
  else
    star(a,b,n/3);
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      star(i,j,n);
    cout << "\n";
  }
} 