#include <iostream>
using namespace std;

int n;
int inorder[100000];
int postorder[100000];
int index[100001];

void preorder(int inS, int inEnd,int postS,int postEnd){
  if(inS > inEnd || postS > postEnd)
    return;

  int root = postorder[postEnd];
  cout << root << " ";
  int leftinEnd = index[root] -1;
  int rightinStart = index[root] +1;
  preorder(inS, leftinEnd, postS, postS + index[root] - inS-1);
  preorder(rightinStart,inEnd, postS + index[root] - inS, postEnd-1);
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i = 0; i< n; i++){
    cin >> inorder[i];
    index[inorder[i]] = i;
  }
  for(int i=0; i<n; i++){
    cin >> postorder[i];
  }
  preorder(0,n-1, 0, n-1);
} 