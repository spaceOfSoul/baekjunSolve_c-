#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,a,b;
int arr[10001];//time
int indegree[10001];//tasks
int memory[10001];//minTime
vector<int> graph[10001];

int result;

void tsort(){
  queue<int> que;
  for(int i=1; i<= n; i++){
    if(indegree[i] == 0){
      que.push(i);
      memory[i] = max(arr[i], memory[i]);
    }
  }

  while(!que.empty()){
    int x = que.front();
    que.pop();

    for(int i : graph[x]){
      indegree[i]--;
      if(indegree[i] == 0)
        que.push(i);

      memory[i] = max(memory[i], arr[i] + memory[x]);
    }
  }
  for(int i=1; i<=n; i++){
    result = max(result, memory[i]);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> arr[i];
    cin >>indegree[i];
    for(int j=0; j<indegree[i]; j++){
      cin >> b;
      graph[b].push_back(i);
    }
  }
  tsort();
  cout << result;
} 