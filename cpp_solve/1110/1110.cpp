#include <iostream>
using namespace std;

int n;
int count;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  int d = n;
  while(true){
    n = ((n%10)*10)+((n%10)+(n/10))%10;
    count ++;
    if(n==d){
      cout << count;
      break;
    }
  }
} 