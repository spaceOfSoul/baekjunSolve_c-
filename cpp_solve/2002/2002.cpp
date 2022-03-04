#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, result;
map<string, int> cars;
vector<int> vec;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  cin >> n;
  string a;
  for(int i=1; i<=n; i++){
    cin >> a;
    cars[a] = i;
  }

  for(int i=1; i<=n; i++){
    cin >> a;
    vec.push_back(cars[a]);
  }
  for(int i=0; i<n-1; i++){
    for(int j=i+1;j<n; j++){
      if(vec[i] > vec[j]){
        result++;
        break;
      }
    }
  }
  cout << result;
}