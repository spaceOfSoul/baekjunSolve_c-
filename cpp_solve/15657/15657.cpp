#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[8];
int result[8];

void d(int deapth,int srt){
  if(deapth == m){
    for(int i=0; i<m; i++){
      cout << result[i] << ' ';
    }
    cout << "\n";
    return;
  }
  
  for(int i=srt;i<n; i++){
    result[deapth] = arr[i];
    d(deapth+1,i);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  for(int i=0; i< n; i++){
    cin >> arr[i];
  }
  sort(arr, arr+n);
  d(0,0);
} 