#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int indegree[100000];
int parents[100000];
int result;

vector<pair<int, int>> px;
vector<pair<int, int>> py;
vector<pair<int, int>> pz;

vector<pair<int, pair<int, int>>> edges;

int find_parents(int x){
  if(parents[x] == x)return x;
  return parents[x] = find_parents(parents[x]);
}

void union_parents(int a, int b){
  a = find_parents(a);
  b = find_parents(b);

  if(b>a){
    parents[b] = a;
  }else
    parents[a] = b;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;

  for(int i=0; i<n; i++)
    parents[i] = i;

  int x,y,z;
  for(int i=0; i<n; i++){
    cin >> x >> y >> z;
    px.push_back({x,i});
    py.push_back({y,i});
    pz.push_back({z,i});
  }
  sort(px.begin(), px.end());
  sort(py.begin(), py.end());
  sort(pz.begin(), pz.end());

  for(int i=0; i<n-1; i++){
    edges.push_back({px[i+1].first - px[i].first,{px[i].second, px[i+1].second}});
    edges.push_back({py[i+1].first - py[i].first,{py[i].second, py[i+1].second}});
    edges.push_back({pz[i+1].first - pz[i].first,{pz[i].second, pz[i+1].second}});
  }

  sort(edges.begin(), edges.end());

  for(auto i: edges){
    int cost = i.first;
    int a = i.second.first;
    int b = i.second.second;

    if(find_parents(a) != find_parents(b)){
      union_parents(a, b);
      result += cost;
    }
  }
  cout << result;
} 