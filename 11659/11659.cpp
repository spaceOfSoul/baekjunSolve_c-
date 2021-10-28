#include <iostream>
#include <vector>
using namespace std;

int arr[100001];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n,m;
  int sum = 0;
  cin >> n >>m;
  for(int i=0; i<n; i++){
    int a;cin >> a;
    sum+=a;
    arr[i]=sum;
  }
  for(int i=0; i<m; i++){
    int a,b;cin >> a >> b;
    if(a!=1)
      cout << arr[b-1]-arr[a-2]<<"\n";
    else
      cout<< arr[b-1] << "\n";
  }
}