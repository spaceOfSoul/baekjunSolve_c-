#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[200000];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  for(int i=0; i<n; i++)
    cin >> arr[i];

  sort(arr, arr+n);
  int c;
  while(m--){
    cin >> c;
    int ptr = lower_bound(arr, arr+n, c) - arr;
    
    if(ptr<0 || ptr>=n ||arr[ptr] !=c){
      cout << -1;
    }else{
      cout << ptr;
    }
    
    cout << "\n";
  }
} 