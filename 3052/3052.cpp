#include <iostream>
#include <map>
using namespace std;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  map<int,int> dict;

  for(int i=0; i< 10; i++){
    int b;
    cin >> b;

    dict.operator[](b%42);
  }
  cout << dict.size();
}