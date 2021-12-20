#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[100000];
int tree[400000];

int init(int start, int end, int node){
  if(start == end)
    return tree[node] = arr[end];
  int mid = (start + end)/2;
  return tree[node] = min(init(start, mid, node*2), init(mid+1, end, node*2+1));
}

int findMin(int start, int end, int l, int r, int node){
  if(start > r || end < l)
    return 1000000123;
  if(l<=start && end <= r)
    return tree[node];

  int mid = (start+end)/2;
  return min(findMin(start, mid, l,r,node*2), findMin(mid+1, end, l,r,node*2+1));
}

int update(int start, int end, int index, int val, int node){
  if(index < start || index > end)
    return tree[node];
  if(start == end)
    return tree[node] = val;

  int mid = (start+end)/2;
  return tree[node] = min(update(start, mid, index, val, node*2), update(mid+1, end, index, val, node*2+1));
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  init(0,n-1,1);
  cin >> m;
  int a,b,c;
  for(int i=0; i<m; i++){
    cin >> a >> b >> c;
    if(a == 1){
      
      update(0,n-1,b-1,c,1);
    }else{
      cout << findMin(0,n-1,b-1,c-1,1) << "\n";
    }
  }
} 