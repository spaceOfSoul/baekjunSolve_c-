#include <iostream>
using namespace std;
int a,b,count,sum;
int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> a >> b;
  for(int i=1; i<=1000; i++){
    for(int j=0; j<i; j++){
      count++;
      if(a<=count && count <= b){
        sum+=i;
      }else if(b<count){
        cout << sum;
        return 0;
      }
    }
  }
} 