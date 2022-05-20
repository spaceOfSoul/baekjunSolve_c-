#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define KEY iter->first
using namespace std;

map<int, pair<int,vector<int>>> graph;
map<int, bool> visited;
int test_case;

bool bfs(int startRoot){
    queue<int> que;
    visited[startRoot] = true;
    int visitedCount = 0;
    que.push(startRoot);

    while(!que.empty()){
        int now = que.front();
        visitedCount++;
        que.pop();

        for(int i : graph[now].second){
            if(visited[i]){
            return false;
            }
            visited[i] = true;
            que.push(i);
        }
    }
    if(visitedCount == graph.size())
        return true;
    return false;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  while(true){
    test_case++;
    int u,v;
    while(true){
      cin >> u >> v;
      if(u==0&&v==0)
        break;
      else if(u<0&&v<0)
        return 0;
      visited[u] = false;
      visited[v] = false;
      graph[v].first++;
      graph[u].second.push_back(v);
    }

    map<int, pair<int,vector<int>>>::iterator iter;
    int rootKey;
    for(iter = graph.begin(); iter!=graph.end(); iter++){
      if(!graph[KEY].first && graph[KEY].second.size()){
        rootKey = KEY;
      }
    }
    bool isTree = bfs(rootKey);
    if(isTree)
        cout << "Case " << test_case << " is a tree.";
    else
        cout << "Case " << test_case << " is not a tree.";
    cout << "\n";
    graph.clear();
    visited.clear();
  }
  return 0;
}