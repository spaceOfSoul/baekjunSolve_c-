#include <iostream>
#include <vector>
using namespace std;

int t;
int preorder[1000];
int inorder[1000];
int index[1001];

void postorder(int start, int end, int rootIndex){
  int root = preorder[rootIndex];
  for(int i=start; i < end; i++){
    if(inorder[i] == root){
      postorder(start,i, rootIndex+1);
      postorder(i+1, end, rootIndex + i +1-start);
      cout << root << " ";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> t;
  while(t--){
    int n; cin >> n;

    for(int i=0; i<n; i++)
      cin >> preorder[i];
    
    for(int i=0; i<n; i++)
      cin >> inorder[i];
    

    postorder(0,n,0);
    cout << "\n";
  }
} 