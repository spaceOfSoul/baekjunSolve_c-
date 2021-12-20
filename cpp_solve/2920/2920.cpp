#include <iostream>
using namespace std;

int music[8];
int sequence = 0;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  for(int i=0; i<8; i++)
    cin >> music[i];
  for(int i = 1;i<=8;i++){
    if(music[i-1] != i){
      sequence = 1;
      break;
    }
  }
  if(sequence == 1){
    for(int i = 8, j = 0;i>0;i--,j++){
      if(music[j] != i){
        sequence = 2;
        break;
      }
    }
  }
  if(sequence == 0)
    cout << "ascending";
  else if(sequence == 1)
    cout << "descending";
  else
    cout << "mixed";
}