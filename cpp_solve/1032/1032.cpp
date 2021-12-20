#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  string file[50];
  cin >> n;
  for(int i =0; i<n;i++){
    cin >> file[i];
  }
  
  int sameCount = 0;
  for(int i = 0;i <size(file[0]); i++){
    for(int j = 0; j < n; j++){
      if(file[j][i] == file[0][i])
        sameCount++;
      else{
        cout << '?';
        break;
      }
      if(sameCount == n){
        cout << file[0][i];
      }
    }
    sameCount=0;
  }
}