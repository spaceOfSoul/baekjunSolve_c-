#include <iostream>
#include <string>
using namespace std;

string n;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  while(true){
    cin >> n;
    if(n=="0")
      break;
    int size = n.length();
    bool is = true;
    for(int i=0; i<size/2; i++){
      if(n[i] != n[size-i-1]){
        cout << "no\n";
        is = false;
        break;
      }
    }
    if(is)
      cout << "yes\n";
  }
} 