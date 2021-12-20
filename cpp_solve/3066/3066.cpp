#include <iostream>
#include <vector>
using namespace std;

int t,n;
vector<int> lis;

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while(t--){
    cin >> n;
    int a;
    for(int i=0; i<n; i++){
      cin >>a;
      if(lis.empty()||lis.back() < a){
        lis.push_back(a);
      }else{
        int ptr = lower_bound(lis.begin(), lis.end(), a) - lis.begin();
        lis[ptr] = a;
      }
    }
    cout << lis.size() << "\n";
    lis.clear();
  }
} 