#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;

  int d = 0, p = 0;
  char a;
  char flag = 1;
  while (n--) {
    cin >> a;
    if (flag) {
      if (a == 'D')
        d++;
      else
        p++;
    }

    if (d - p >= 2 || p - d >= 2)
      flag = 0;
  }
  cout << d << ':' << p;
}