#include <iostream>
#include <string>
#include <stack>
using namespace std;

int t;
string str;
stack<bool> stk;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> t;

  while(t--){
    cin >> str;
    bool isRight = true;
    for(int i=0; i<str.length(); i++){
      if(str[i] == '(')
        stk.push(true);
      else{
        if(stk.empty()){
          isRight = false;
          break;
        }
        stk.pop();
      }
    }
    if(isRight){
      if(!stk.empty())
        cout << "NO";
      else
        cout << "YES";
    }else{
      cout << "NO";
    }
    cout << "\n";
    while(!stk.empty())
      stk.pop();
  }  
} 