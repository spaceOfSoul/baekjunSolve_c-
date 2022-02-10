#include <iostream>
using namespace std;

int n;
int cows[10];
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  int a,b;
  while(n--){
    cin >> a >> b;
    a--;b++;
    if(!cows[a]){
      cows[a] = b;
    }else{
      if(cows[a]!=b){
        result++;
        cows[a] = b;
      }
    }
  }
  cout << result;
}