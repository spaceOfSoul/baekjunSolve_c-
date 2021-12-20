#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int n;
vector<int> graph[100001];
int submit[100000];
bool visited[100001];

int ptr = 1;

bool bfs(){
  queue<int> que;
  que.push(1);
  visited[1] = true;

  while(!que.empty()){
    int now = que.front();
    que.pop();
    set<int> resultStan;
    for(int i=0; i < graph[now].size(); i++){
      if(visited[graph[now][i]])
        continue;

      visited[graph[now][i]] = true;
      resultStan.insert(graph[now][i]);
    }
    for(int i=0; i< resultStan.size(); i++){
      if(resultStan.find(submit[ptr]) == resultStan.end())
        return false;
      
      que.push(submit[ptr]);
      ptr++;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=0; i<n-1; i++){
    int a,b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for(int i=0; i< n; i++){
    cin >> submit[i];
  }
  if(submit[0] != 1)
    cout << 0;
  else
    cout << bfs();
} 