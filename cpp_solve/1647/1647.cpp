#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<pair<int, pair<int, int>>> line;
int parents[100001];
int result;

int findParents(int a){
  if(parents[a] == a) return a;
  return parents[a] = findParents(parents[a]);
}

void unionParents(int a, int b){
  a = findParents(a);
  b = findParents(b);
  
  if(a<b)
    parents[b] = a;
  else
    parents[a] = b;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  for(int i=1; i<=n; i++)
    parents[i] = i;
  
  int a,b,c;
  for(int i=0; i<m; i++){
    cin >> a >> b >> c;
    line.push_back({c,{a,b}});
  }
  sort(line.begin(), line.end());

  int last;
  for(auto i : line){
    int c = i.first;
    int a = i.second.first;
    int b = i.second.second;

    if(findParents(a) != findParents(b)){
      unionParents(a, b);
      last = c;
      result += c;
    }
  }
  cout << result-last;
} 