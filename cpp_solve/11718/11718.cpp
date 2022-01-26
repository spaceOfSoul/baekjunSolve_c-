#include <iostream>
#include <string>
using namespace std;

string asd;

int main() {
  while(true){
    getline(cin,asd);
    if(asd=="")
      break;
    cout << asd << "\n";
  }
} 