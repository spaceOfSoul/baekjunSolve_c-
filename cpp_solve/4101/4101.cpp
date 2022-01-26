#include <iostream>
using namespace std;
int main() {
  int a,b;
  while(true){
    cin >> a >> b;
    if(!a&&!b)
      break;
    if(a>b)
      cout << "Yes\n";
    else{
      cout<<"No\n";
    }
  }
} 