#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n;
  int opinions[300001];

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> opinions[i];
  }

  if (n == 0) {
    cout << "0";
    return 0;
  }

  sort(opinions, opinions + n);

  int beExcluded = round(n * 0.15);

  int sum = 0;
  for (int i = beExcluded; i < n - beExcluded; i++) {
    sum += opinions[i];
  }

  cout << round((double)sum / (n - 2 * beExcluded));
  return 0;
}