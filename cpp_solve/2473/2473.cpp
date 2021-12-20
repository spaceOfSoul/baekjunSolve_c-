#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long arr[5000];
long long result = 9999999999;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=0; i<n; i++)
    cin >> arr[i];

  sort(arr, arr+n);
  
  long long first,mid, last;
  for(int i=0;i<n; i++){
    int start = i+1;
    int end = n-1;
    while(start<end){
      long long sum = arr[start] + arr[end] + arr[i];
      long long stan = abs(sum);

      if(result > stan){
        result = stan;
        first = arr[i];
        mid = arr[start];
        last = arr[end];
      }

      if(sum > 0){
        end--;
      }else
        start++;
    }
  }
  cout << first << " " << mid << " " << last;
}