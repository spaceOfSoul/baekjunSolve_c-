#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> chickenJip;
vector<pair<int, int>> houses;
vector<pair<int, int>> selected;
int result = 999999999;

void dfs(int deapth, int stanC){
  int chickenDist = 0;
  if(deapth == m){
    for(pair<int, int> i : houses){
      int x = i.first;
      int y = i.second;
      int dist = 999999999;
      for(pair<int, int> j : selected){
        int nx = j.first;
        int ny = j.second;
        dist = min(dist, abs(nx-x)+abs(ny-y));
      }
      chickenDist += dist;
    }
    result = min(result, chickenDist);
  }
  for(int i=stanC; i< chickenJip.size();i++){
    selected.push_back(chickenJip[i]);
    dfs(deapth+1, i+1);
    selected.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;
  int a;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> a;
      if(a == 2){
        chickenJip.push_back({i,j});
      }
      else if(a == 1){
        houses.push_back({i,j});
      }
    }
  }
  
  dfs(0,0);
  cout << result;
} 