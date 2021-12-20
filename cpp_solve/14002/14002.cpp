#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
pair<int, int> arr[1000];
int navi[1000];
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i].first;
    arr[i].second = 1;
  }

  int result = 1;
  int idx = 0;
  for(int i=0; i<n; i++){
    navi[i] = -1;
    for(int j=0; j<i; j++){
      if(arr[j].first < arr[i].first){
        if(arr[i].second < arr[j].second+1){
          arr[i].second = arr[j].second+1;
          navi[i] = j;
        }
      }
    }
    
    if(arr[i].second>result){
      result = arr[i].second;
      idx = i;
    }
  }
  cout << result << "\n";

  stack<int> stk;
  while(idx != -1){
    stk.push(arr[idx].first);
    idx = navi[idx];
  }
  while(!stk.empty()){
    cout << stk.top() << " ";
    stk.pop();
  }
} 