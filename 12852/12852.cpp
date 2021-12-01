#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000001];
int navi[1000001];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=2; i<= n; i++){
    arr[i] = arr[i-1] +1;
    navi[i] = i-1;
    if(i%2 == 0 && arr[i] > arr[i/2]+1){
      arr[i] = arr[i/2]+1;
      navi[i] = i/2;
    }
    if(i%3 == 0 && arr[i] > arr[i/3] +1){
      arr[i] = arr[i/3]+1;
      navi[i] = i/3;
    }
  }
  cout << arr[n] << "\n";
  while(n != 0){
    cout << n << " ";
    n = navi[n];
  }
} 