#include <iostream>
using namespace std;

int n;
int arr[20][20];
bool minRoad[20][20];
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> arr[i][j];
    }
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        if(i==j||j==k||i==k)
          continue;
        if(arr[j][k] > arr[j][i]+arr[i][k]){
          cout << -1;
          return 0;
        }else if(arr[j][k]==arr[j][i]+arr[i][k]){
          minRoad[j][k] = true;
        }
      }
    }
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(!minRoad[i][j])
        result+=arr[i][j];
    }
  }
  cout << result/2;
}