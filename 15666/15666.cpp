#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[8];
int result[8];

void nm(int deapth, int before){
  if(deapth == m){
    for(int i=0; i<m; i++){
      cout << result[i] <<" ";
    }
    cout << "\n";
    return;
  }

  int notThis = 0;
  for(int i=before; i< n; i++){
    if(arr[i] == notThis)
      continue;
    result[deapth] = notThis = arr[i];
    nm(deapth+1,i);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr, arr+n);
  nm(0,0);
} 