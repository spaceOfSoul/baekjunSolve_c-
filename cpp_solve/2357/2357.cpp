#include <iostream>
#include <algorithm>
using namespace std;

int n,m,a,b;

int arr[100000];
int maxTree[400000];
int minTree[400000];

int initMax(int start, int end, int node){
  if(start==end)
    return maxTree[node] = arr[start];
  int mid = (start+end)/2;
  return maxTree[node] = max(initMax(start,mid,node*2), initMax(mid+1, end, node*2+1));
}

int initMin(int start, int end, int node){
  if(start == end)
    return minTree[node] = arr[start];
  int mid = (start+end)/2;
  return minTree[node] = min(initMin(start,mid,node*2), initMin(mid+1,end,node*2+1)); 
}

int FindMax(int start, int end, int left, int right, int node){
  if(left> end || right <start)
    return 0;
  if(left <=start && right >= end)
    return maxTree[node];

  int mid = (start+end)/2;
  return max(FindMax(start,mid,left,right,node*2), FindMax(mid+1,end,left,right,node*2+1));
}

int FindMin(int start, int end, int left, int right, int node){
  if(left> end || right <start)
    return 1000000123;
  if(left <=start && right >= end)
    return minTree[node];

  int mid = (start+end)/2;
  return min(FindMin(start,mid,left,right,node*2), FindMin(mid+1,end,left,right,node*2+1));
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;
  for(int i=0; i<n; i++)
    cin >> arr[i];

  initMax(0,n-1,1);
  initMin(0,n-1,1);
  for(int i=0; i<m; i++){
    cin >> a >> b;
    cout << FindMin(0,n-1,a-1,b-1,1) << " " << FindMax(0,n-1,a-1,b-1,1) << "\n";
  }
} 