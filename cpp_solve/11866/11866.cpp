#include <iostream>
#include <queue>
using namespace std;

int n,k;

int main() {
  ios::sync_with_stdio(false);
  queue<int> que;
  cin >> n >> k;
  for(int i=1; i<=n; i++){
    que.push(i);
  }
  cout << "<";
  while(!que.empty()){
    for(int i=0; i<k-1;i++){
      que.push(que.front());
      que.pop();
    }
     cout << que.front();
     que.pop();
    if(!que.empty())
      cout << ", ";
  }
  cout << ">";
} 