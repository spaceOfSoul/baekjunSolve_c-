#include <iostream>
using namespace std;

int n;
int arr[1000000];
int b, c;
long long result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i];
  cin >> b >> c;
  result=n;
  for(int i=0; i<n; i++){
    arr[i] = arr[i]-b;
    if(arr[i]>0){
      result+=(arr[i]/c);
      if(arr[i]%c)
        result++;
    }
  }
  cout << result;
} 