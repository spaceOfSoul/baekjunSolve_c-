#include <iostream>
#include <stack>
#include <string>
using namespace std;

string str;
stack<char> stk;
int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  while(true){
    bool isBalence = true;
    getline(cin, str);
    if(str.size() == 1 && str[0] == '.')
      break;
    
    for(int i=0; i<str.size(); i++){
      if(str[i] == '(' || str[i]=='['){
        stk.push(str[i]);
      }else if(str[i] == ')' || str[i] == ']'){
        if(stk.empty()){
          isBalence = false;
          break;
        }
        if(str[i] == ')' && stk.top() != '('){
          isBalence = false;
          break;
        }
        if(str[i] == ']' && stk.top() != '['){
          isBalence = false;
          break;
        }
        stk.pop();
      }
    }
    if(isBalence && stk.empty())
      cout << "yes\n";
    else{
      cout << "no\n";
    }
    while(!stk.empty()){
      stk.pop();
    }
  }
} 