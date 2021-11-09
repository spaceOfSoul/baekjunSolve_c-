#include <iostream>
using namespace std;

int n;
int ways[100000];
int jooyuso[100000];
long long result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;

  for(int i=0; i< n-1; i++){
    cin >> ways[i];
  }
  for(int i=0; i<n; i++){
    cin >> jooyuso[i];
  }
  int nowCost = jooyuso[0];
  for(int i=0; i < n-1; i++){
    if(nowCost > jooyuso[i]){
      nowCost = jooyuso[i];
    }
    result += ((long long)nowCost * (long long)ways[i]);
  }
  cout << result;
} 