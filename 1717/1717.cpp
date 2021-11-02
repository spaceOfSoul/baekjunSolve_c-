#include <iostream>
#include <vector>
using namespace std;

int n,m;
int parents[1000001];

int find_parents(int a){
  if(parents[a] == a) return a;
  parents[a] = find_parents(parents[a]);
  return parents[a];
}

void union_parents(int a, int b){
  a = find_parents(a);
  b = find_parents(b);
  if (a<b)
    parents[b] = a;
  else
    parents[a] = b;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;
  for(int i=1; i<=n; i++){
    parents[i] = i;
  }

  for(int i=0; i<m; i++){
    int c,a,b;
    cin >> c >> a >> b;

    if(c){
      if(find_parents(a) == find_parents(b))
        cout << "YES" << "\n";
      else
        cout << "NO" << "\n";
    }else{
      union_parents(a,b);
    }
  }
} 