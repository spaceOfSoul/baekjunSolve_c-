#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;

  int a;
  for(int i=0; i<n; i++){
    cin >> a;
    if(result.empty() || result.back() < a)
      result.push_back(a);
    else{
      int ptr = lower_bound(result.begin(),result.end(), a) - result.begin();
      result[ptr]=a;
    }
  }
  cout << result.size();
} 