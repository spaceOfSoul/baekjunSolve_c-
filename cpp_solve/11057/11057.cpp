#include <iostream>
#define NN 10007
#define N 1000

using namespace std;

int arr[N + 1][11];
int result;

int main() {
  int n;
  cin >> n;

  int i, j;
  for (i = 1; i <= 10; i++) {
    arr[0][i] = 1;
  }
  for (i = 1; i < n; i++) {
    for (j = 1; j <= 10; j++) {
      arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % NN;
    }
  }
  for (int i = 1; i <= 10; i++) {
    result += arr[n - 1][i];
  }
  cout << result % NN;
}