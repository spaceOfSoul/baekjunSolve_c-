#include <iostream>
#include <algorithm>
using namespace std;

int t;
int arr[10];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> t;
  while(t--){
    for(int i=0; i<10; i++){
      cin >> arr[i];
    }
    sort(arr, arr+10);
    cout << arr[7] << "\n";
  }
} 