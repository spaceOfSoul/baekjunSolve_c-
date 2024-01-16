#include <algorithm>
#include <iostream>
using namespace std;

int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int arr[500000];

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);

  cin >> m;

  int a;
  while (m--) {
    cin >> a;
    int index = lower_bound(arr, arr + n, a) - arr;
    if (index != n && arr[index] == a) {
      cout << 1 << " ";
    } else {
      cout << 0 << " ";
    }
  }
}