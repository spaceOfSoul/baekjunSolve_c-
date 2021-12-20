#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> result;
int index[1000000];
int list[1000000];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> list[i];
    if(result.empty() || result.back() < list[i]){
      result.push_back(list[i]);
      index[i] = result.size()-1;
    }else{
      int ptr = lower_bound(result.begin(),result.end(), list[i]) - result.begin();
      result[ptr]=list[i];
      index[i] = ptr;
    }
  }
  int resultSize = result.size();
  cout << resultSize << "\n";
  stack<int> stk;
  for(int i = n-1; i>=0; i--){
    if(index[i] == resultSize-1){
      stk.push(list[i]);
      resultSize--;
    }
  }
  while(!stk.empty()){
    cout << stk.top() << " ";
    stk.pop();
  }
} 