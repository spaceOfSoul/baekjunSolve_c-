#include <iostream>
#include <map>
#include <string>
using namespace std;

int t;

int main() {
  ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
  cin >> t;
  while(t--){
    int n;
    map<string, int> closet;
    cin >> n;
    while(n--){
      string a,b;
      cin >> a >> b;
      if(closet.find(b) == closet.end())
        closet[b] = 1;
      else
        closet[b]++;
    }
    int result = 1;
    for(auto i : closet){
      result *= ++i.second;
    }
    cout << --result<<"\n";
  }
}