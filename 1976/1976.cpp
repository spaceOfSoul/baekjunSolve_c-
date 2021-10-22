#include <iostream>
using namespace std;

int n,m;
int parents[200];

int findParents(int x){
  if(parents[x] != x) return findParents(parents[x]);
  return x;
}

void union_parent(int a, int b){
  a = findParents(a);
  b = findParents(b);
  if (a<b)
    parents[b] = a;
  else
    parents[a] = b;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=0; i < n; i++)
    parents[i] = i;
  
  cin >> m;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      int k;
      cin >> k;
      if(k==1)
        union_parent(i, j);
    }
  }

  int root;
  bool enable =true;
  for(int i =0; i<m;i++){
    int nxtCity;
    cin >> nxtCity;
    nxtCity--;
    if(enable){
      if(i == 0)
        root = findParents(nxtCity);
      else{
        if(root != findParents(nxtCity))
          enable = false;
      }
    }
  }
  if(enable)
    cout << "YES";
  else
    cout << "NO";
}