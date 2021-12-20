#include <iostream>
#include <algorithm>
using namespace std;

bool chessboard[50][50];
int result =999999999;
int n,m;

int paint(int x, int y){
  int eox = x+8;
  int eoy =y+8;
  bool stan = chessboard[x][y];
  int count = 0;
  for(int i=x; i<eox; i++){
    for(int j=y; j<eoy; j++){
      if(chessboard[i][j] != stan){
        count++;
      }
      if(stan)
        stan = false;
      else
        stan = true;
    }
    if(stan)
      stan = false;
    else
      stan = true;
  }
  return min(count, 64-count);
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n >> m;

  char a;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> a;
      if(a == 'B')
        chessboard[i][j] = true;
      else
        chessboard[i][j] = false;
    }
  }
  
  for(int i=0; i<n-7; i++){
    for(int j=0; j<m-7; j++){
      result = min(result, paint(i,j));
    }
  }
  cout << result;
} 