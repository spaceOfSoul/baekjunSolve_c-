#include <iostream>
using namespace std;

int n;
int chessPan[15];
int result;

void postQueens(int count){
  if(count == n){
    result++;
    return;
  }

  bool postable = true;
  for(int i=0; i< n; i++){
    //is enable?
    for(int j =0; j< count; j++){
      if(i == chessPan[j] || abs(i-chessPan[j]) == count-j){
        postable = false;
        break;
      }
    }
    if(!postable){
      postable = true;
      continue;
    }
    
    chessPan[count] = i;
    postQueens(count+1);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  postQueens(0);
  cout << result;
} 