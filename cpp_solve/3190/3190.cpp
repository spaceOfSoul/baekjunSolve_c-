#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int n,k,l;

int arr[100][100];
deque<pair<int, int>> snake;
deque<pair<int, char>> commend;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  cin >> k;
  int a,b;
  for(int i=0; i<k; i++){
    cin >> a >> b;
    arr[a-1][b-1] = 1;
  }
  char c;
  cin >> l;
  for(int i=0; i<l; i++){
    cin >> b >> c;
    commend.push_back({b,c});
  }

  int dr = 0;
  snake.push_back({0,0});
  arr[0][0] = 2;
  while(true){
    result++;
    int x = snake.front().first;
    int y = snake.front().second;
    
    int nx = x + dx[dr];
    int ny = y + dy[dr];
    if(0<=nx && nx<n && 0<=ny && ny <n){
      if(arr[nx][ny] == 2){
        break;
      }else if(arr[nx][ny] == 1){
        arr[nx][ny]=2;
      }else{
        arr[nx][ny]=2;
        arr[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
      }
      snake.push_front({nx,ny});
    }else{
      break;
    }
    if(result==commend.front().first){
      if(commend.front().second=='L'){
        dr--;
        if(dr==-1)
          dr=3;
      }else{
        dr++;
        if(dr==4)
          dr = 0;
      }
      commend.pop_front();
    }
  }
  cout << result;
} 