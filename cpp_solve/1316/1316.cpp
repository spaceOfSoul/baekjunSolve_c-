#include <iostream>
#include <string>
#include <set>
using namespace std;

int n;
int result;
int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  result = n;
  
  string a;
  while(n--){
    cin >> a;
    char tmp ='.';
    set<char> chars;
    for(int i=0; i<a.size(); i++){
      if(chars.empty() || chars.find(a[i]) == chars.end()){
        chars.insert(a[i]);
        tmp = a[i];
      }else if(chars.find(a[i]) != chars.end()){
        if(tmp!= a[i]){
          result--;
          break;
        }
      }
    }
  }
  cout << result;
} 