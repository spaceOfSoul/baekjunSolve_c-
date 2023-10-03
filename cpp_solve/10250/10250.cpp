#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  int H, W, N;

  int x, y;

  cin >> T;
  while (T--) {
    cin >> H >> W >> N;

    y = N % H;
    x = N / H + 1;

    if (!y) {
      y = H;
      x--;
    }

    string back = x < 10 ? "0" + to_string(x) : to_string(x);

    cout << to_string(y) << back << "\n";
  }
}