#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
double arr[100000];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> k;
  for(int i=0; i<n; i++)
    cin >> arr[i];

  sort(arr, arr+n);
  double tmp=0;
  for(int i=k;i<n-k; i++){
    tmp+=arr[i];
  }
  cout << fixed;
  cout.precision(2);
  cout << tmp/(n-2*k)+(1e-13) << "\n";
  tmp=0;
  for(int i=0; i<k; i++){
    tmp+=arr[k];
    tmp+=arr[n-k-1];
  }
  for(int i=k;i<n-k; i++)
    tmp+=arr[i];
  
  cout << tmp/n+(1e-13);
}