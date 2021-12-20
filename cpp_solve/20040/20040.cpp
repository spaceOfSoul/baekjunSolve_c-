#include <iostream>
using namespace std;

int n,m;
int parents[500000];

int findParent(int a){
  if(parents[a] == a) return a;
  return parents[a] = findParent(parents[a]);
}

void union_parents(int a, int b){
  a = findParent(a);
  b = findParent(b);

  if(a<b)
      parents[b] = a;
  else
    parents[a] = b;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;

  for(int i=0; i<n; i++)
    parents[i] = i;

  int result = 0;
  for(int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    if(findParent(a) == findParent(b)){
      result = i+1;
      break;
    }else
      union_parents(a,b);
  }
  cout << result;
} 