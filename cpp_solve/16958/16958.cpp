#include <cmath>
#include <iostream>
#include <vector>
#define INF 999999999
using namespace std;

typedef struct city {
  int first, second, special;
} city;

int n, t, m;
city citys[1000];
vector<int> special;
int table[1000][1000];

void set_table() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        table[i][j] = 0;
      } else {
        table[i][j] = abs(citys[i].first - citys[j].first) +
                      abs(citys[i].second - citys[j].second);
        if (citys[i].special && citys[j].special) {
          if (table[i][j] > t)
            table[i][j] = t;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (table[j][k] > table[j][i] + table[i][k])
          table[j][k] = table[j][i] + table[i][k];
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> t;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      table[i][j] = INF;
  }

  int s;
  for (int i = 0; i < n; i++) {
    cin >> citys[i].special >> citys[i].first >> citys[i].second;
  }

  set_table();
  cin >> m;
  int a, b;
  while (m--) {
    cin >> a >> b;
    cout << table[a - 1][b - 1] << "\n";
  }
}