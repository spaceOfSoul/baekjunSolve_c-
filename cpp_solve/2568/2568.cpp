#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> result;
vector<int> index;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  int a,b;
  for(int i=0; i < n; i++){
    cin >> a >> b;
    arr.push_back({a,b});
  }
  sort(arr.begin(), arr.end());
  for(auto i : arr){
    a = i.second;
    if(result.empty() || result.back() < a){
      result.push_back(a);
      index.push_back(result.size()-1);
    }else{
      int idx = lower_bound(result.begin(),result.end(), a) - result.begin();
      result[idx] = a;
      index.push_back(idx);
    }
  }

  int resultSize = result.size();
  cout << n- resultSize << "\n";
  resultSize--;

  vector<int> stk;
  for(int i = n-1; i>=0; i--){
    if(resultSize == index[i]){
      resultSize--;
    }else
      stk.push_back(arr[i].first);
  }
  sort(stk.begin(),stk.end());
  for(int i:stk){
    cout << i << "\n";
  }
} 