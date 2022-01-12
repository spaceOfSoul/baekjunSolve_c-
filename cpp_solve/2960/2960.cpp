#include <iostream>
using namespace std;

int n,k;
bool prime[1001];
int count;

int main() {
  cin >> n >> k;
  for(int i=2; i<=n; i++){
    if(prime[i])
      continue;
    for(int j=i; j<=n; j+=i){
      if(!prime[j]){
      prime[j] = true;
      count++;
      if(count == k){
        cout << j;
        return 0;
      }
        }
    }
  }
} 