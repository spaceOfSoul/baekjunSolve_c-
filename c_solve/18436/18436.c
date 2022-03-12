#include <stdio.h>

int arr[100000];
int tree[400000];

int n,m;

int init(int start, int end, int node){
  if(start == end)
    return tree[node] = arr[start]%2;
  
  int mid = (start + end) / 2;
  return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

int even(int s, int e, int l, int r, int node){
  if(r < s || e < l)
    return 0;
  if(l<=s && r>=e)
    return tree[node];

  int mid = (s+e)/2;
  return even(s,mid,l,r,node*2) + even(mid+1,e,l,r,node*2+1);
}

void update(int s, int e, int node, int index, int val){
  if(s<= index && index <= e){
    tree[node] += val;
    if(s==e)
      return;
    int mid = (s+e)/2;
    update(s,mid,node*2,index, val);
    update(mid+1,e,node*2+1,index,val);
  }
}

int main(void) {
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", arr+i);
  }

  init(0, n-1, 1);

  scanf("%d", &m);
  int a,b,c;
  while(m--){
    scanf("%d %d %d",&a,&b,&c);
    if(a==1){
      int tmp =c%2;
      b--;
      if(arr[b]%2 == tmp)
        continue;
      arr[b] = c;
      if(!tmp)
        tmp=-1;
      update(0, n-1, 1, b,tmp);
    }else if(a==2){
      printf("%d\n", (c-b+1) - even(0,n-1, b-1,c-1,1));
    }else if(a==3){
      printf("%d\n", even(0,n-1, b-1,c-1,1));
    }
  }
  return 0;
}