#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,p;
int d[400];
bool visited[400];
int flow[400][400];
int cap[400][400];
vector<int> graph[400];
int result;

void maxflow(){
  while(true){
    fill(d,d+n, -1);
    queue<int> que;
    que.push(0);

    while(!que.empty()){
      int x = que.front();
      que.pop();

      for(int nxt:graph[x]){
        if(cap[x][nxt] - flow[x][nxt] >0 && d[nxt] == -1){
          d[nxt] = x;
          que.push(nxt);
          if(nxt == 1)
            break;
        }
      }
    }
    if(d[1] == -1)
      break;
    bool duplication = false;
    for(int i=1; i!=0; i=d[i]){
      if(i!=1 && visited[i]){
        duplication = true;
      }
      visited[i] = true;
      flow[i][d[i]]--;
      flow[d[i]][i]++;
    }
    if(!duplication)
      result++;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);
  cin >> n >> p;

  int a,b;
  while(p--){
    cin >> a >> b;
    a--;b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
    cap[a][b] = 1;
    cap[b][a] = 1;
  }
  maxflow();
  cout << result;
} 