#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,a,b;
int arr[2000];
vector<int> v1, v2;
int result1[2000];
int result2[2000];
int result;
pair<int, int> trains[2000];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> trains[i].first;
    trains[i].second = i;
  }
  sort(trains, trains+n);

  for(int i=0; i<n; i++){
    a = -trains[i].second;
    if(v1.empty() || v1.back() < a){
      v1.push_back(a);
    }else{
      int ptr = lower_bound(v1.begin(), v1.end(), a) - v1.begin();
      v1[ptr] = a;
    }
    result1[i] = v1.size();
  }

  for(int i=n-1; i>=0; i--){
    a = -trains[i].second;
    if(v2.empty() || v2.back() < a){
      v2.push_back(a);
    }else{
      int ptr = lower_bound(v2.begin(), v2.end(), a) - v2.begin();
      v2[ptr] = a;
    }
    result2[i] = v2.size();
  }
  for(int i=0; i<n; i++)
    result = max(result, result1[i]+result2[i]-1);
  cout << result;
} 