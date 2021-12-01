#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
priority_queue<int> endTime;
vector<pair<int, int>> arr; 

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  int a,b;
  for(int i=0; i<n; i++){
    cin >> a >> b;
    arr.push_back({a,b});
  }
  sort(arr.begin(), arr.end());

  for(pair<int, int>i:arr){
    //cout << i.first << " " << i.second << "\n";
    if(!endTime.empty() && i.first >= -endTime.top()){
      endTime.pop();
    }
    endTime.push(-i.second);
  }
  cout << endTime.size();
} 