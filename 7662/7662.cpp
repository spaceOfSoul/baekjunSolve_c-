#include <iostream>
#include <set>
#include <list>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  multiset<int> que;
  int t;
  cin >> t;

  for(int i =0; i < t; i++){
    int k;
    cin >> k;
    for(int j = 0; j < k; j++){
      char commend;
      int num;
      cin >> commend >> num;
      if(commend == 'I'){
        que.insert(num);
      }else{
        if(!que.empty()){
          if(num == 1)
            que.erase(--que.end());
          else
            que.erase(que.begin());
        }
      }
    }

    if(que.empty()){
      cout << "EMPTY\n";
    }else{
      cout << *--que.end() << " " << *que.begin() << "\n";
    }
    que.clear();
  }
}