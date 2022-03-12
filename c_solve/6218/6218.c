#include <stdio.h>

int n, q;
int arr[50000];
int minTree[200000];
int maxTree[200000];

int min(int a, int b){
  if(a<b)
    return a;
  return b;
}

int max(int a, int b){
  if(a>b)
    return a;
  return b;
}

int minInit(int s, int e, int node){
  if(s==e)
    return minTree[node] = arr[s];
  int mid = (s+e)/2;
  return minTree[node] = min( minInit(s,mid, node*2), minInit(mid+1, e, node*2+1) );
}

int maxInit(int s, int e, int node){
  if(s==e)
    return maxTree[node] = arr[s];
  int mid = (s+e)/2;
  return maxTree[node] = max(maxInit(s,mid, node*2), maxInit(mid+1, e, node*2+1));
}

int findMin(int s, int e, int l, int r, int node){
  if(r<s || e<l)
    return 1000001;
  if(l<=s && e<=r)
    return minTree[node];
  int mid = (s+e)/2;
  return min(findMin(s, mid, l, r, node*2), findMin(mid+1,e,l,r, node*2+1));
}

int findMax(int s, int e, int l, int r, int node){
  if(r<s || e<l)
    return 0;
  if(l<=s && e<=r)
    return maxTree[node];
  int mid = (s+e)/2;
  return max( findMax(s, mid, l, r, node*2), findMax(mid+1, e, l, r, node*2+1) );
}

int main(void) {
  scanf("%d %d", &n, &q);
  for(int i=0; i<n; i++)
    scanf("%d", arr+i);

  minInit(0, n-1, 1);
  maxInit(0,n-1,1);
  int a,b;
  while(q--){
    scanf("%d %d", &a, &b);
    a--;b--;
    int minVal = findMin(0,n-1,a,b,1);
    int maxVal = findMax(0, n-1, a,b,1);
    printf("%d\n", maxVal - minVal);
  }
  return 0;
}