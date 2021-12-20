#include <iostream>
#include <queue>
using namespace std;

int bfs(long long a, long long b){
  queue<pair<long long, int>> que;
  que.push({a,1});
  while(!que.empty()){
    long long pos = que.front().first;
    int step = que.front().second;
    que.pop();
    if(pos == b)
      return step;
    for(long long i: {pos * 2, (pos * 10 + 1)}){
      if(i > b)
        continue;
      que.push({i,step+1});
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  long long a,b;
  cin >> a >> b;
  cout << bfs(a,b);
}