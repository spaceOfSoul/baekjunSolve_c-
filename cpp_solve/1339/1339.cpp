#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
bool used[10];
bool usedChar[26];
int ptr = 9;
pair<int, string> num[10];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> num[i].second;
    num[i].first = num[i].second.size();
  }
  sort(num, num+n, greater<pair<int, string>>());
  for(auto i: num){
    cout << i.first << " " << i.second << "\n";
  }
} 