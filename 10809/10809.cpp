#include <iostream>
#include <string>
using namespace std;

int alphabet[26] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int main() {
  string qwer;
  cin >> qwer;
  for(int i =0; i<qwer.size(); i++){
    for(int j = 0; j < 26; j++){
      if((int)(qwer[i] - 'a') == j && alphabet[j] == -1)
        alphabet[j] = i;
    }
  }
  for(int i=0; i<26;i++){
    cout << alphabet[i] << " ";
  }
}