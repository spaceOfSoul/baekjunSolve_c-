#include <iostream>
using namespace std;

int result;
bool prime[1001];

int main() {
  for(int i=2; i<=1000; i++){
    if(prime[i]) 
      continue;
    for(int j=2*i; j<=1000; j+=i){
      prime[j] = true;
    }
  }
  prime[1] = true;
  int n,a;cin >> n;
  while(n--){
    cin >> a;
    if(!prime[a])
      result++;
  }
  cout << result;
}