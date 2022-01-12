#include <iostream>
#include <algorithm>
using namespace std;

int n,m;

int arr[500000];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i];

  sort(arr, arr+n);

  cin >> m;

  int a;
  while(m--){
    cin >> a;
    if(arr[lower_bound(arr, arr+n, a) - arr] == a){
      cout << 1 << " ";
    }else{
      cout << 0 << " ";
    }
  }
} 