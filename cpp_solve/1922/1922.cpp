#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, pair<int,int>>> network;
int n,m;
int parents[1000];
int result = 0;

int findparent(int x){
  if (parents[x] != x)
    parents[x] = findparent(parents[x]);
  return parents[x];
}

void unionParents(int a, int b){
  a = findparent(a);
  b = findparent(b);

  if(a<b)
    parents[b] = a;
  else
    parents[a] = b;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  cin >> m;
  for(int i =0; i<n; i++){
    parents[i] = i;
  }
  for(int i = 0; i < m; i++){
    int a,b,c;
    cin >> a >> b >> c;
    network.push_back({c,{a-1,b-1}});
  }

  sort(network.begin(), network.end());

  for(int i =0; i < network.size(); i++){
    int cost = network[i].first;
    int a = network[i].second.first;
    int b = network[i].second.second;

    if(findparent(a) != findparent(b)){
      unionParents(a,b);
      result += cost;
    }
  }
  cout << result;
}