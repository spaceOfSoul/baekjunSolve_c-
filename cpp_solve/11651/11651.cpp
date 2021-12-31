#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[100000];
int main() {
  cin >> n;
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  for(int i=0; i<n; i++)
    cin >> arr[i].second >> arr[i].first;

  sort(arr, arr+n);
  for(int i=0; i<n; i++)
    cout << arr[i].second << " " << arr[i].first<<"\n";
} 