#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int> card;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;

  for(int i =0; i<n; i++){
    int a;
    cin >> a;
    card.push(-a);
  }
  int a,b,result;
  result = 0;
  while(card.size() > 1){
    a = -card.top();
    card.pop();
    b = -card.top();
    card.pop();
    result+= (a+b);
    card.push(-(a+b));
  }
  cout << result;
}