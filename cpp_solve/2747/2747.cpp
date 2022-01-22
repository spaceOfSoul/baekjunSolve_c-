#include <iostream>
using namespace std;

int arr[46]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597,};

int main() {
  int n;
  cin >> n;
  for(int i=18; i<=n; i++){
    arr[i] = arr[i-1]+arr[i-2];
  }
  cout << arr[n];
} 