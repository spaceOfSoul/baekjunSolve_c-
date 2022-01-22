#include <iostream>
using namespace std;

int x1,y1,x2,y2,x3,y3,x4,y4;

int ccw(int a1, int b1, int a2, int b2, int a3, int b3){
  int tmp = a1*b2 + a2*b3 + a3*b1;
  tmp -= (a2*b1 + a3*b2 + a1*b3);

  if(tmp>0)return 1;
  else if(tmp < 0) return -1;
  else return 0;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);

  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >>x4 >> y4;
  if(ccw(x1,y1,x2,y2,x3,y3)*ccw(x1,y1,x2,y2,x4,y4)<0
    && ccw(x3,y3,x4,y4,x1,y1)*ccw(x3,y3,x4,y4,x2,y2)<0){
      cout << 1;
    }else{
      cout << 0;
    }
} 