#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    stack<char> stk;
    string str;
    getline(cin,str);

    bool in_bracket = false;
    for(char c: str){
        if(c == '<'){
            in_bracket = true;
            while(!stk.empty()){
                cout << stk.top();
                stk.pop();
            }
        }else if(c=='>'){
            in_bracket = false;
          cout << '>';
          continue;
        }

        if(c==' '){
          if(in_bracket){
            cout << c;
          }else{
            while(!stk.empty()){
              cout << stk.top();
              stk.pop();
            }
            cout << ' ';
          }
        }
        else{
          if(!in_bracket)
            stk.push(c);
          else{
            cout << c;
          }
        }
    }
    while(!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
    return 0;
}
