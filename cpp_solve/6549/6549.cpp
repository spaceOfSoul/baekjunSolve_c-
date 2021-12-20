#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100000];
int tree[400000];
long long result;

int init(int start, int end, int node){
  if(start == end){
    return tree[node] = end;
  }
  int mid = (start+end)/2;
  int left = init(start, mid, node*2);
  int right = init(mid+1, end, node*2+1);
  if(arr[left]<arr[right])
    return tree[node] = left;
  else{
    return tree[node]= right;
  }
}

//범위 내에 가장 작은 친구의 인덱스를 반환
int getIndex(int start, int end, int node, int left, int right){
  if(start > right || end < left)
    return -1;
  if(left <= start && right >= end)
    return tree[node];

  int mid = (start + end) / 2;
  int li = getIndex(start,mid, node*2, left, right);
  int ri = getIndex(mid+1,end,node*2+1,left,right);

  if(li == -1)
    return ri;
  else if(ri == -1)
    return li;

  if(arr[li] < arr[ri])
    return li;
  else{
    return ri;
  }
}
void maxArea(int left, int right){
  if(left > right)
    return;

  int index = getIndex(0,n-1,1,left, right);
  result = max(result, (long long)arr[index] *(right-left+1));
  
  maxArea(left, index-1);
  maxArea(index+1,right);
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  while(true){
    cin >> n;
    if(!n)
      break;
    for(int i=0; i<n; i++){
      cin >> arr[i];
    }

    init(0,n-1,1);
    maxArea(0, n-1);
    cout << result << "\n";
    result = 0;
  }
} 