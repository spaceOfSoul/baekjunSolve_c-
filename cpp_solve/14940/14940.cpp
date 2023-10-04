#include <iostream>
#include <queue>

using namespace std;

int arr[1000][1000];
int visited[1000][1000];

int n, m, x, y;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
  queue<pair<int, int>> que;

  que.push({x, y});
  visited[x][y] = 0;

  int nx, ny, cx, cy;

  while (!que.empty()) {
    cx = que.front().first;
    cy = que.front().second;
    que.pop();

    for (int i = 0; i < 4; i++) {
      nx = cx + dx[i];
      ny = cy + dy[i];
      if ((0 <= nx && nx < n) && (0 <= ny && ny < m)) {
        if ((nx == x && ny == y) || visited[nx][ny] != -1)
          continue;

        if (arr[nx][ny] == 0)
          continue;

        visited[nx][ny] = visited[cx][cy] + 1;
        // cout << "visited [nx][ny] : " << visited[nx][ny];
        que.push({nx, ny});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 2) {
        x = i;
        y = j;
      }
      visited[i][j] = -1;
    }
  }

  bfs();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0) {
        cout << 0 << " ";
        continue;
      }
      cout << visited[i][j] << " ";
    }
    cout << "\n";
  }
}