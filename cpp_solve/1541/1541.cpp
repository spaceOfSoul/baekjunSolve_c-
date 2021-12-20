#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main() {
  string sik;
  cin >> sik;
  string oneNum = "";

  bool inBrackit = false;
  int result = 0;

  for (int i = 0; i < sik.size(); i++){
    if(sik[i] == '+' || sik[i] == '-'){
      if(inBrackit){
        result -= stoi(oneNum);
      }else{
        result += stoi(oneNum);
        if(sik[i] == '-')
          inBrackit = true;
      }
      oneNum = "";
      continue;
    }
    oneNum += sik[i];
    if(i == sik.size()-1){
      if(inBrackit)
        result -= stoi(oneNum);
      else
        result += stoi(oneNum);
    }
  }
  cout << result << "\n";
}