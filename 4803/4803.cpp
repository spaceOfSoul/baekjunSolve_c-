#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int testCase;
vector<int> graph[501];
bool visited[501];

bool dfs(int v,int before){
  visited[v] = true;
  for(int i:graph[v]){
    if(visited[i]){
      if(i != before)
        return false;
    }else{
      if(dfs(i,v) == false)
        return false;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  while(true){
    testCase++;
    int n,m;
    cin >> n >> m;
    if(n ==0 && m ==0)
      break;

    for(int i=1; i<=n; i++){
      graph[i].clear();
      visited[i] = false;
    }

    bool cycle = false;
    for(int i=0; i<m; i++){
      int a,b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    int result = 0;
    for(int i = 1; i<=n; i++){
      if(!visited[i]){
        if(dfs(i,i))
          result++;
      }
    }
    if(result > 1)
      cout << "Case " << testCase << ": A forest of " << result << " trees." <<"\n";
    else if(result == 1)
      cout << "Case " << testCase << ": There is one tree." << "\n";
    else
      cout << "Case " << testCase << ": No trees." << "\n";
  }
} 