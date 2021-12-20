#include <iostream>
using namespace std;
long long n;

long long stan[2][2] = {{1,1},{1,0}};
long long result[2][2] = {{0,1},{1,0}};

void multiMatrix(long long a[2][2], long long b[2][2]){
  long long tmp[2][2];
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      tmp[i][j] = 0;
      for(int k=0; k<2; k++)
        tmp[i][j] += (a[i][k] * b[k][j]);
      tmp[i][j] %= 1000000;
    }
  }

  for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
      b[i][j] = tmp[i][j];
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  while(n > 0){
    if(n%2 == 1)
      multiMatrix(stan, result);
    multiMatrix(stan, stan);
    n/=2;
  }
  cout << result[0][0];
}  