#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> paper;
int result[3];

void oxtobi(int r, int c, int nn){
  int stan = paper[r][c];
  for(int i=r; i<nn+r; i++){
    for(int j=c; j< nn+c; j++){
      if (paper[i][j] != stan){
        oxtobi(r+nn/3, c, nn/3);
        oxtobi(r+2*nn/3, c, nn/3);
        oxtobi(r, c, nn/3);
        oxtobi(r, c+nn/3, nn/3);
        oxtobi(r, c+nn/3*2, nn/3);
        oxtobi(r+nn/3, c+nn/3, nn/3);
        oxtobi(r+nn/3, c+nn/3*2, nn/3);
        oxtobi(r+nn/3*2, c+nn/3, nn/3);
        oxtobi(r+nn/3*2, c+nn/3*2, nn/3);
        return;
      }
    }
  }

  result[++stan]++;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  cin >> n;
  for(int i=0; i<n; i++){
    vector<int> arr;
    for(int j=0; j<n; j++){
      int a;
      cin >> a;
      arr.push_back(a);
    }
    paper.push_back(arr);
  }
  oxtobi(0, 0, n);
  cout << result[0] << "\n" << result[1] << "\n" << result[2];
}