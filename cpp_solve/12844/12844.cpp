#include <stdio.h>

int tree[2000000];
int arr[500000];
int lazy[2000000];

int n,m;

int init(int s, int e, int node){
  if(s==e){
    return tree[node] = arr[s];
  }

  int mid = (s+e)/2;
  return tree[node] = init(s,mid,node*2) ^ init(mid+1, e, node*2+1);
}

void update(int s, int e, int l, int r, int node, int val){
  if(lazy[node]){
    if((e-s+1)%2)
      tree[node] ^= lazy[node];
    if(s!=e){
      lazy[node*2] ^= lazy[node];
      lazy[node*2+1] ^= lazy[node];
    }
    lazy[node] = 0;
  }

  if(e < l || r < s)
    return;

  if(l<=s&& e<=r){
    if((e-s+1)%2)
      tree[node] ^= val;
    if(s!=e){
      lazy[node*2] ^= val;
      lazy[node*2+1] ^= val;
    }
    return;
  }

  int mid = (s+e)/2;
  update(s, mid, l, r, node*2, val);
  update(mid+1,e,l,r,node*2+1,val);
  tree[node] = tree[node*2] ^ tree[node*2+1];
}

int query(int s, int e, int l, int r, int node){
  if(lazy[node]){
    if((e-s+1)%2)
      tree[node] ^= lazy[node];
    if(s!=e){
      lazy[node*2] ^= lazy[node];
      lazy[node*2+1] ^= lazy[node];
    }
    lazy[node] = 0;
  }

  if(e < l || r < s)
    return 0;
  if(l <= s && e<= r)
    return tree[node];
  
  int mid = (s+e)/2;
  return query(s,mid,l,r,node*2)^query(mid+1,e,l,r, node*2+1);
}

int main(void) {
  scanf("%d", &n);

  for(int i=0; i<n; i++)
    scanf("%d", arr+i);

  init(0,n-1,1);

  scanf("%d",&m);
  
  int q,l,r,k;
  while(m--){
    scanf("%d", &q);
    if(q==2){
      scanf("%d %d",&l, &r);
      if(l>r){
        int tmp = l;
        l=r;
        r=tmp;
      }
      printf("%d\n", query(0,n-1,l,r,1));
    }else{
      scanf("%d %d %d",&l, &r, &k);

      if(l>r){
        int tmp = l;
        l=r;
        r=tmp;
      }
      
      update(0, n-1, l, r, 1, k);
    }
  }
  return 0;
}