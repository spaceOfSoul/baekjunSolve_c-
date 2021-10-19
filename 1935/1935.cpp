#include <iostream>
#include <string>
#include <stack>
using namespace std;
int piyunsan[26];

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
  cout<<fixed;cout.precision(2);

  int n;
  string sic;

  cin >> n;
  cin >> sic;
  for(int i = 0; i < n;i++)
    cin >> piyunsan[i];
  
  stack<double> stk;
  for(int i = 0; i < size(sic); i++){
    if(sic[i]>='A'&&sic[i]<='Z')
      stk.push(piyunsan[sic[i]-'A']);
    else{
      double a = stk.top();
      stk.pop();
      double b = stk.top();
      stk.pop();

      if(sic[i]=='+')
        stk.push(b+a);
      else if(sic[i]=='-')
        stk.push(b-a);
      else if(sic[i]=='*')
        stk.push(b*a);
      else if(sic[i]=='/')
        stk.push(b/a);
    }
  }
  cout << stk.top();
}