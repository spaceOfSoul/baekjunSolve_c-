#include <iostream>
using namespace std;

int arr[100000];
int tree[400000];
int n,k;


int init(int start, int end, int node){
  if(start == end)
    return tree[node]=arr[start];
  int mid = (start + end)/2;
  return tree[node] = init(start, mid, node*2) * init(mid+1, end, node*2+1);
}

int multi(int s, int e, int l, int r, int node){
  if(r<s || e<l)
    return 1;
  if(l<=s && e<=r)
    return tree[node];
  int mid = (s+e)/2;
  return multi(s,mid,l,r,node*2) * multi(mid+1,e,l,r,node*2+1);
}

int update(int s, int e, int index, int val, int node){
  if(index < s || e < index)
    return tree[node];
  if(s == e)
    return tree[node] = val;

  int mid = (s+e)/2;
  return tree[node] = update(s,mid,index,val,node*2) * update(mid+1,e, index, val, node*2+1);
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  while(cin >> n){
    cin >> k;
    for(int i=0; i<n; i++){
      cin >> arr[i];
      if(arr[i] >0)
        arr[i] = 1;
      else if(arr[i] < 0)
        arr[i] = -1;
      else{
        arr[i] = 0;
      }
    }

    init(0,n-1,1);
    
    char a;
    int b, c;
    while(k--){
      cin >> a >> b >> c;
      b--;
      if(a == 'P'){
        c--;
        int res = multi(0,n-1,b,c,1);
        if(res == 1){
          cout << '+';
        }else if(res == -1){
          cout << '-';
        }else{
          cout << 0;
        }
      }else{
        if(c > 0){
          c = 1;
        }else if(c < 0){
          c = -1;
        }else{
          c = 0;
        }
        update(0,n-1,b,c,1);
      }
    }
    cout << "\n";
  }
} 