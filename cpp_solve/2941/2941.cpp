#include <iostream>
#include <string>
using namespace std;

string str;
bool c,d,l,n,s,z;
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> str;
  for(int i=1; i<str.size(); i++){
    if(str[i] == '='){
      if(str[i-1] == 'c'||str[i-1] == 's'){
        result++;
      }else if(str[i-1] == 'z'){
        result++;
        if(i>1){
          if(str[i-2] == 'd')
            result++;
        }
      }
    }else if(str[i] == '-'){
      if(str[i-1]=='c'||str[i-1]=='d')
        result++;
    }else if(str[i] == 'j'){
      if(str[i-1]=='l'||str[i-1]=='n')
        result++;
    }
  }
  cout << str.size()-result*2+result;
}