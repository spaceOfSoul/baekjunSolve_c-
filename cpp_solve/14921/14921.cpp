#include <iostream>
using namespace std;

int n;
int arr[100000];
int result = 2000002222;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);
  cin >> n;

  

  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  int i=0;
  int j = n-1;
  while(i<j){
    int sum = arr[i] + arr[j];
    int stan = abs(sum);
    if(stan < abs(result))
      result = sum;
    if(sum > 0)
      j--;
    else
      i++;
  }
  cout << result;
} 