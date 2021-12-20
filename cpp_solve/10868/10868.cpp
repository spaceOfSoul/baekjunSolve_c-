#include <iostream>
#include <algorithm>
using namespace std;

int n,m,a,b;

int arr[100000];
int tree[400000];

int init(int start, int end, int node){
  if(start == end)
    return tree[node] = arr[start];
  
  int mid = (start+end)/2;
  return tree[node] = min(init(start,mid,node*2), init(mid +1, end, node*2+1));
}

int FindMin(int start, int end, int left, int right, int node){
  if(start > right || left > end)
    return 1000000123;
  if(start >= left && right >= end)
    return tree[node];
  
  int mid = (start+end)/2;
  return min(FindMin(start,mid,left,right,node*2), FindMin(mid+1, end, left, right, node * 2+1));
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;
  for(int i=0; i<n; i++)
    cin >> arr[i];
  
  init(0,n-1,1);
  for(int i=0;i<m; i++){
    cin >> a >> b;
    cout << FindMin(0, n-1, a-1, b-1, 1) << "\n";
  }
} 