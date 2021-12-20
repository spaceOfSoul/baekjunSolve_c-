#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,c;
vector<int> houses;
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);
  cin >> n >> c;

  int a;
  for(int i=0; i<n; i++){
    cin >> a;
    houses.push_back(a);
  }
  sort(houses.begin(), houses.end());

  int start = 1;
  int end = houses[n-1] - houses[0];
  int mid;
  int point;
  int count;
  while(start <= end){
    mid = (start + end)/2;
    point = houses[0];
    count =1;

    for(int i=1; i<n; i++){
      if(houses[i]>= mid+point){
        point = houses[i];
        count++;
      }
    }

    if(count >= c){
      start = mid+1;
      result = mid;
    }else
      end = mid-1;
  }
  cout << result;
} 