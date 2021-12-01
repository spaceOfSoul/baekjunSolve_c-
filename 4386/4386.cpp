#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
vector<pair<double, double>> starPos;
vector<pair<double, pair<int, int>>> edge;
int parents[100];
double result;

int findParents(int a){
  if(parents[a] == a) return a;
  return parents[a] = findParents(parents[a]);
}

void union_parants(int a, int b){
  a = findParents(a);
  b = findParents(b);
  if(a<b)
    parents[b] = a;
  else
    parents[a] = b;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cout << fixed;
  cout.precision(2);
  cin >> n;
  double x,y;
  for(int i=0; i<n; i++){
    cin >> x >> y;
    starPos.push_back({x,y});
    parents[i] = i;
  }
  for(int i = 0; i<n; i++){
    double nowx = starPos[i].first;
    double nowy = starPos[i].second;
    for(int j = i+1; j<n; j++){
      double nx = starPos[j].first;
      double ny = starPos[j].second;

      double dx = pow(nowx-nx,2);
      double dy = pow(nowy-ny,2);
      edge.push_back({sqrt(dx+dy), {i, j}});
    }
  }

  sort(edge.begin(), edge.end());

  for(auto i: edge){
    double dist = i.first;
    int a = i.second.first;
    int b = i.second.second;

    if(findParents(a) != findParents(b)){
      union_parants(a,b);
      result += dist;
    }
  }
  cout << result;
} 