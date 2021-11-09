#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<pair<int, int>> tree[10001];
int maxLenth;
int stan;
bool visited[10001];

void dfs(int v, int nowSum){
  if(visited[v])
    return;
  
  visited[v] = true;

  if(nowSum > maxLenth){
    maxLenth = nowSum;
    stan = v;
  }
  for(pair<int, int> i:tree[v]){
    dfs(i.first, nowSum + i.second);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i< n-1; i++){
    int a,b,c;
    cin >> a >> b >> c;
    tree[a].push_back({b,c});
    tree[b].push_back({a,c});
  }
  dfs(1,0);
  maxLenth = 0;
  memset(visited, false, sizeof(visited));
  dfs(stan,0);
  cout << maxLenth;
} 