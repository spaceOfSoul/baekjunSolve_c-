#include <iostream>
#include <algorithm>
using namespace std;

int n,s;
int arr[50];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i];
  cin >> s;

  for(int i=0; i<n; i++){
    if(!s)
      break;
    int maxNum = arr[i];
    int index = -1;
    
    for(int j=i+1; j<n; j++){
      if(s-(j-i) < 0)
        break;
      if(maxNum < arr[j]){
        maxNum = arr[j];
        index = j;
      }
    }
    for(int j=index; j> i; j--){
      swap(arr[j], arr[j-1]);
      s--;
    }
  }
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
} 