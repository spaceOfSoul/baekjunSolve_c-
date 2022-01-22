#include <iostream>
using namespace std;
int sum;
int minNum=999999999;
int main() {
  int a;
  for(int i=0; i<7; i++){
    cin >> a;
    if(a%2!=0){
      sum+=a;
      if(a<minNum)
        minNum = a;
    }
  }
  if(!sum){
    cout << -1;
    return 0;
  }else{
    cout << sum << "\n";
    cout << minNum;
  }
}
