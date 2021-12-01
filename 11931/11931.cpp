#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000000];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  int max = 0;
  for(int i=0; i<n; i++){
    cin >> arr[i];
    
  }
  
  sort(arr, arr+n, greater<int>());
  for(int i=0; i<n; i++){
    cout << arr[i] << "\n";
  }
} 