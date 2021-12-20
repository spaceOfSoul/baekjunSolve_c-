#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  int a;
  for(int i=0; i<n; i++){
    cin >> a;
    if(arr.empty() || arr.back() < a){
      arr.push_back(a);
    }else{
      int ptr = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
      arr[ptr] = a;
    }
  }
  cout << n - arr.size();
} 