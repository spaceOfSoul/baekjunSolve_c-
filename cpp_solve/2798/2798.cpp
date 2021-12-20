#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n,m;
  cin >> n >> m;
  int card[n];

  for(int i = 0; i<n; i++){
    cin >> card[i];
  }

  bool find = false;
  int result = 0;
  for(int i = 0; i < n; i++){
    if(find)break;
    for(int j = 0; j < n; j++){
      if(find)break;
      if(j == i) continue;
        for(int k = 0; k < n; k++){
          if(k == i || k == j) continue;
          if(card[i]+card[j]+card[k] < m && card[i]+card[j]+card[k]>result){
            result = card[i]+card[j]+card[k];
          }else if(card[i]+card[j]+card[k] == m){
            cout << card[i]+card[j]+card[k];
            find = true;
            break;
          }
        }
    }
  }
  if(!find)
    cout << result;
}