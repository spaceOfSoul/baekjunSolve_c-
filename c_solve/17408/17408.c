#include <stdio.h>

typedef struct pair{
  int first,second;
}pair;

pair tree[400000];
int arr[100000];
int n,m;

pair makepair(int a, int b){
  pair tmp = {a,b};
  return tmp;
}

pair sortPair(pair a, pair b){
  int arr[4] = {a.first, a.second, b.first, b.second};
  for(int i=1; i<4; i++){
    int val = arr[i];
    int j;
    for(j=i-1; j>=0 && arr[j]<val; j--){
      arr[j+1] = arr[j];
    }
    arr[j+1] = val;
  }
  return makepair(arr[0],arr[1]);
}

pair init(int s, int e, int node){
  if(s==e){
    return tree[node] = makepair(arr[s], 0);
  }

  int mid = (s+e)/2;
  return tree[node] = sortPair(init(s,mid,node*2), init(mid+1, e, node*2+1));
}

pair update(int s, int e, int a, int val, int node){
  if(a < s || e < a)
    return tree[node];
  if(s==e)
    return tree[node]= makepair(val, 0);

  int mid = (s+e)/2;
  return tree[node] = sortPair(update(s,mid,a,val, node*2), update(mid+1, e,a,val,node*2+1));
}

pair query(int s, int e, int l, int r, int node){
  if(e<l || r<s)
    return makepair(-1,-1);
  if(l<=s&&e<=r)
    return tree[node];

  int mid = (s+e)/2;
  return sortPair(query(s,mid,l,r,node*2), query(mid+1,e,l,r,node*2+1));
}

int main(void) {
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", arr+i);
  }
  init(0,n-1,1);
  scanf("%d", &m);

  int q, a,b;
  while(m--){
    scanf("%d %d %d",&q,&a,&b);
    a--;
    if(q==1){
      update(0,n-1,a,b,1);
    }else{
      b--;
      pair tmp = query(0, n-1, a, b , 1);
      printf("%d\n", tmp.first+tmp.second);
    }
  }
  return 0;
}