#include <iostream>
using namespace std;

int n;
int arr[50][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i][0] >> arr[i][1];
  
  for(int i=0; i<n; i++){
    int rank = 1;
    for(int j = 0; j<n; j++)
      if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
        rank++;
    cout << rank << " ";
  }
} 