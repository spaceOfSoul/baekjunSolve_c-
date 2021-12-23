#include <iostream>
#include <vector>
using namespace std;

int n,m;
char arr[50][50];
vector<pair<int, int>> paint;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> arr[i][j];
      if(arr[i][j] != '.')
        paint.push_back({i,j});
    }
  }

  for(auto i:paint){
    arr[i.first][m-i.second-1] = arr[i.first][i.second];
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout << arr[i][j];
    }
    cout << "\n";
  }
} 