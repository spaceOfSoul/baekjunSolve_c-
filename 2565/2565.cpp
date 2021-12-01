#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  int a, b;
  for(int i=0; i<n; i++){
    cin >> a >> b;
    arr.push_back({a,b});
  }
  sort(arr.begin(), arr.end());
  for(auto i:arr){
    a = i.second;
    if(result.empty() || result.back() < a){
      result.push_back(a);
    }else{
      int ptr = lower_bound(result.begin(), result.end(), a) - result.begin();
      result[ptr] = a;
    }
  }
  cout << n - result.size();
} 