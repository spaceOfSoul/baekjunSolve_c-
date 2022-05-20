#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,m, posr=1,posc,d, sr, sc;
    cin >> n >> m;
    cin >> posc >> d;
    cin >> sr >> sc;

    d = d ? 1 : -1;
    while(posr!=n||posc!=m){
      int nc = posc+d;
      if(1<=nc&&nc<=m){
        posc = nc;
      }else{
        posr++;
        d*=-1;
      }
      if(posr == sr && posc == sc){
        cout << "NO...";
        return 0;
      }
    }
  cout << "YES!";
}