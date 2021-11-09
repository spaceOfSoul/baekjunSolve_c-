#include <iostream>
#include <stack>
using namespace std;

int a;
stack<int> stk;
int arr[1000000];
int result[1000000];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> a;
  for(int i=0; i<a; i++){
    cin >> arr[i];
  }
  
  for(int i=a-1; i>=0; i--){
    while(!stk.empty() && stk.top() <= arr[i])
      stk.pop();

    if(stk.empty())
      result[i] = -1;
    else 
      result[i] = stk.top();
    stk.push(arr[i]);
  }
  for(int i=0; i<a; i++){
    cout << result[i] << " ";
  }
}