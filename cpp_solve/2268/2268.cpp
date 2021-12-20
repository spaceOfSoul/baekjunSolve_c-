#include <iostream>
using namespace std;
typedef long long ll;

int n,m;
ll arr[1000000];
ll tree[4000000];

ll sum(int start, int end, int l, int r, int node){
  if(start >r || end < l)
    return 0;
  if(l<= start && end <= r)
    return tree[node];
  
  int mid = (start + end)/2;
  return sum(start, mid, l, r, node*2) + sum(mid+1,end,l,r,node*2+1);
}

void update(int s, int e, int index, int node, ll diff){
  if(s <= index && index <= e){
    tree[node] += diff;

    if(s ==e)
      return;

    int mid = (s+e)/2;
    update(s,mid,index,node*2, diff);
    update(mid+1,e,index,node*2+1, diff);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  ll a,b,c;
  for(int i=0; i<m; i++){
    cin >> a >> b >> c;
    b--;
    if(a){
      ll dif = c - arr[b];
      arr[b] = c;
      update(0,n-1,b,1,dif);
    }else{
      c--;
      if(b>c)
        cout << sum(0,n-1,c,b,1) << "\n";
      else
        cout << sum(0,n-1,b,c,1) << "\n";
    }
  }
} 