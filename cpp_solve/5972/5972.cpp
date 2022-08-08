#include <iostream>
#include <queue>
#include <vector>

#define INF 999999999
#define MAX_VERTEX 50000

using namespace std;

const int start = 0;
int n, m;
vector<pair<int, int>> graph[MAX_VERTEX];
int dist[MAX_VERTEX];

void findPath() {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      que;
  que.push({start, 0});
  dist[start] = 0;

  while (!que.empty()) {
    pair<int, int> ver = que.top();
    que.pop();

    int now = ver.first;
    int nowDist = ver.second;

    if (dist[now] < nowDist)
      continue;

    for (pair<int, int> i : graph[now]) {
      int nextDist = i.second + nowDist;
      if (nextDist < dist[i.first]) {
        dist[i.first] = nextDist;
        que.push({i.first, nextDist});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    dist[i] = INF;

  int a_i, b_i, c_i;
  while (m--) {
    cin >> a_i >> b_i >> c_i;
    a_i--;
    b_i--;
    graph[a_i].push_back({b_i, c_i});
    graph[b_i].push_back({a_i, c_i});
  }
  findPath();
  cout << dist[n - 1];
}