#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int n, m;
int arr[100001];
ll tree[400001];

typedef struct triple {
  int first, second, third;
  int index;
} triple;

bool compare(triple a, triple b) {
  if (a.first < b.first)
    return true;
  return false;
}

vector<pair<int, int>> updateQuery;
vector<triple> outQuery;
ll result[100001];

ll init(int s, int e, int node) {
  if (s == e)
    return tree[node] = arr[s];
  int mid = (s + e) / 2;
  return tree[node] = init(s, mid, node * 2) + init(mid + 1, e, node * 2 + 1);
}

void update(int s, int e, int index, int dif, int node) {
  if (s <= index && index <= e) {
    tree[node] += dif;

    if (s == e)
      return;

    int mid = (s + e) / 2;
    update(s, mid, index, dif, node * 2);
    update(mid + 1, e, index, dif, node * 2 + 1);
  }
}

ll sum(int s, int e, int l, int r, int node) {
  if (e < l || r < s)
    return 0;
  if (l <= s && e <= r)
    return tree[node];

  int mid = (s + e) / 2;
  return sum(s, mid, l, r, node * 2) + sum(mid + 1, e, l, r, node * 2 + 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  init(0, n - 1, 1);

  cin >> m;
  int q, a, b, c;
  int execute = 0;
  while (m--) {
    cin >> q;
    if (q == 1) {
      cin >> a >> b;
      updateQuery.push_back({a, b});
    } else {
      cin >> a >> b >> c;
      outQuery.push_back({a, b, c, execute});
      execute++;
    }
  }

  sort(outQuery.begin(), outQuery.end(), compare);

  int commendTime = 0;
  int record = 0;

  for (triple i : outQuery) {
    if (i.first > commendTime) {
      for (int j = commendTime; j < i.first; j++) {
        pair<int, int> tmp = updateQuery[j];
        int dif = tmp.second - arr[tmp.first - 1];
        arr[tmp.first - 1] = tmp.second;

        update(0, n - 1, tmp.first - 1, dif, 1);
      }
      commendTime = i.first;
    }

    result[i.index] = sum(0, n - 1, i.second - 1, i.third - 1, 1);
  }

  int querySize = outQuery.size();
  for (int i = 0; i < querySize; i++)
    cout << result[i] << "\n";
}