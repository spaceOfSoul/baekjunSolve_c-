#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> list[201];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;

  for(int i = 0; i< n; i++){
    int age;
    string name;
    cin >> age >> name;
    list[age].push_back(name);
  }

  for(int i=1;i <= 200; i++){
    for(int j = 0; j<list[i].size(); j++)
      cout << i << " " << list[i][j] << "\n";
  }
}