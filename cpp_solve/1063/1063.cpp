#include <iostream>
#include <string>
using namespace std;

int x,y,stonex,stoney,t;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string a;
  cin >> a;
  x=a[0]-'A';y=a[1]-'1';
  cin >> a;
  stonex = a[0]-'A';stoney = a[1]-'1';
  cin >> t;
  while(t--){
    cin >> a;
    int nx,ny;
    if(a=="T"){
      nx=x;
      ny=y+1;
    }else if(a=="B"){
      nx=x;
      ny=y-1;
    }else if(a=="L"){
      nx=x-1;
      ny=y;
    }else if(a=="R"){
      nx=x+1;
      ny=y;
    }else if(a=="RT"){
      nx=x+1;
      ny=1+y;
    }else if(a=="RB"){
      nx=1+x;
      ny=y-1;
    }else if(a=="LT"){
      nx=x-1;
      ny=1+y;
    }else if(a=="LB"){
      nx=x-1;
      ny=y-1;
    }
    if(0<=nx&&nx<8&&0<=ny&&ny<8){
      if(nx==stonex&&ny==stoney){
        int snx = stonex + (nx-x);
        int sny = stoney + (ny-y);
        if(0<=snx&&snx<8&&0<=sny&&sny<8){
          x=nx;y=ny;
          stonex=snx;stoney=sny;
        }
      }else{
        x=nx;y=ny;
      }
    }
  }
  cout << (char)('A'+x) << (char)('1'+y) << "\n";
  cout << (char)('A'+stonex) << (char)('1'+stoney);
}