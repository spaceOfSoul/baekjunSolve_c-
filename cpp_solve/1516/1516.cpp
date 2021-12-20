#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;

pair<int, vector<int>> buildSequence[500];
int result[500];
int indegree[500];

void tSort(){
  queue<int> que;
  for(int i=0; i<n; i++){
    if(indegree[i] == 0){
      que.push(i);
      result[i] = buildSequence[i].first;
    }
  }

  while(!que.empty()){
    int now = que.front();
    que.pop();

    for(int i: buildSequence[now].second){
      indegree[i]--;
      result[i] = max(result[i], result[now] + buildSequence[i].first);
      if(!indegree[i])
        que.push(i);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  
  int a;
  for(int i=0; i<n; i++){
    cin >> buildSequence[i].first;

    while(true){
      cin >> a;
      if(a == -1)
        break;
      buildSequence[a-1].second.push_back(i);
      indegree[i]++;
    }
  }

  tSort();

  for(int i=0; i<n; i++){
    cout << result[i] << "\n";
  }
} 