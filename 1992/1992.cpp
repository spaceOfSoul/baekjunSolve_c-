#include <iostream>
#include <string>
using namespace std;

int n;
string video[64];

void videoCopress(int x, int y, int nn){
  char chkPoint = video[x][y];
  bool same = true;

  for(int i=x; i < x+nn; i++){
    if(!same)
      break;
    for(int j =y; j<y+nn; j++){
      if(chkPoint != video[i][j]){
        same = false;
        break;
      }
    }
  }

  if(same)
    cout << chkPoint;
  else{
    cout << "(";
    videoCopress(x,y,nn/2);
    videoCopress(x,y + nn/2,nn/2);
    videoCopress(x + nn/2,y,nn/2);
    videoCopress(x + nn/2,y + nn/2,nn/2);
    cout<<")";
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=0; i<n;i++)
    cin >> video[i];

  videoCopress(0,0,n);
}