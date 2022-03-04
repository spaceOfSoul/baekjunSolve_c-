#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> deq;
int n;
string commend;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  while(n--){
    cin >> commend;
    if(commend == "push_front"){
      int x;cin >> x;
      deq.push_front(x);
    }else if(commend == "push_back"){
      int x;cin >> x;
      deq.push_back(x);
    }else if(commend == "pop_front"){
      if(deq.empty())
        cout << -1 << "\n";
      else{
        cout << deq.front() << "\n";
        deq.pop_front();
      }
    }else if(commend == "pop_back"){
      if(deq.empty())
        cout << -1 << "\n";
      else{
        cout << deq.back() << "\n";
        deq.pop_back();
      }
    }else if(commend == "size"){
      cout << deq.size() << "\n";
    }else if(commend == "empty"){
      if(deq.empty())
        cout << 1 << "\n";
      else
        cout << 0  << "\n";
    }else if(commend=="front"){
      if(deq.empty())
        cout << -1 << "\n";
      else
        cout << deq.front() << "\n";
    }else if(commend=="back"){
      if(deq.empty())
        cout << -1 << "\n";
      else
        cout << deq.back() << "\n";
    }
  }
}