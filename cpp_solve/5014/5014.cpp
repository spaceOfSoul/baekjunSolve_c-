#include <iostream>
#include <queue>
using namespace std;

int visited[1000001];
int f, s, g, u, d;

void bfs(){
  queue<int> que;
  que.push(s);
  visited[s] = 1;
  
  while(!que.empty()){
    int now = que.front();
    que.pop();

    if(now == g)
      return;

    for(int i:{u,-d}){
      int nxt = now+i;
      if(0<nxt && nxt <= f && !visited[nxt]){
        visited[nxt] = visited[now]+1;
        que.push(nxt);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> f >> s >> g >> u >> d;
  bfs();
  if(!visited[g])
    cout << "use the stairs";
  else
    cout << visited[g]-1;
}