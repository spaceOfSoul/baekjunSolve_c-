#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long result;

int arr[100000];
long long tree[400000];//트리엔 인덱스

int init(int start, int end,int node){
  if(start == end)
    return tree[node] = start;

  int mid = (start+ end)/2;
  int lVal = init(start, mid, node*2);
  int rVal = init(mid+1,end,node*2+1);
  if(arr[lVal] > arr[rVal])
    return tree[node] = rVal;
  else
    return tree[node] = lVal;
}

int getIndex(int start, int end, int left, int right, int node){
  if(left <= start && end <= right)
    return tree[node];
  if(start > right || end < left)
    return -1;

  int mid = (start+end)/2;
  int lVal = getIndex(start, mid, left, right, node*2);
  int rVal = getIndex(mid+1,end,left,right, node*2+1);

  if(lVal == -1)
    return rVal;
  else if(rVal == -1)
    return lVal;

  if(arr[rVal]<arr[lVal])
    return rVal;
  else
    return lVal;
}

void maxArea(int left, int right){
  if(left > right)
    return;
  int index = getIndex(0,n-1,left,right,1);
  result = max(result, (long long)arr[index] *(right-left+1));

  maxArea(left, index-1);
  maxArea(index+1,right);
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  init(0,n-1,1);
  maxArea(0,n-1);
  cout << result;
} 