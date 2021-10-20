#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> curriculum[32000];
int indegree[32000] = {0,};
int n,m;

void tsrot(){
  priority_queue<int, vector<int>, greater<int>> que;
  for(int i = 0; i < n; i++){
    if(indegree[i] == 0)
      que.push(i);
  }
  
  while(!que.empty()){
    int now = que.top();
    que.pop();
    cout << now+1 << " ";
    for(int i =0; i< curriculum[now].size(); i++){
      indegree[curriculum[now][i]]-=1;
      if(indegree[curriculum[now][i]] == 0)
        que.push(curriculum[now][i]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  for(int i=0; i < m; i++){
    int a,b;
    cin >> a >> b;
    curriculum[a-1].push_back(b-1);
    indegree[b-1]++;
  }
  tsrot();
}