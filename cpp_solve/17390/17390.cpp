#include <iostream>
#include <algorithm>
using namespace std;

int n,q;
int arr[300001];
int sum[300001];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> q;
  for(int i=1; i<=n; i++)
    cin >> arr[i];

  sort(arr+1, arr+n+1);
  for(int i=1; i<=n; i++)
    sum[i] = sum[i-1]+arr[i];

  int a,b;
  while(q--){
    cin >> a >> b;
    cout << sum[b]-sum[a-1] << "\n";
  }
} 