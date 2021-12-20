#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int n;
bool isPrime[2000001];

bool isPelrindrom(int num){
  string snum = to_string(num);
  int sSize = snum.size();
  for(int i=0; i<sSize/2; i++){
    if(snum[i] != snum[sSize - 1 - i])
      return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  memset(isPrime, true, sizeof(isPrime));
  isPrime[1] = false;
  for(int i= 2; i*i < 2000001; i++){
    if(!isPrime[i])
      continue;
    for(int j=2*i;j<2000001; j+=i){
      isPrime[j] = false;
    }
  }
  for(int i=n; i<2000001; i++){
    if(isPrime[i] && isPelrindrom(i)){
      cout << i;
      break;
    }
  }
  
} 