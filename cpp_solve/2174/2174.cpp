#include <iostream>
#include <vector>
using namespace std;

int a,b,n,m;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
pair<int, int> grp[101][101];
vector<pair<int, int>> robots;

int direction(char d){
  if(d=='N')
    return 0;
  if(d == 'W')
    return 3;
  if(d == 'E')
    return 1;
  if(d=='S')
    return 2;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> a >> b >> n >> m;
  robots.push_back({0,0});
  for(int i=1; i<=n; i++){
    char tmp;int x,y;
    cin >> x >> y >> tmp;
    grp[x][y].first = i;
    grp[x][y].second = direction(tmp);
    robots.push_back({x,y});
  }
  
  int r,c;
  char dir;
  while(m--){
    cin >> r >> dir >> c;
      int x = robots[r].first;
      int y = robots[r].second;
      int nowdir = grp[x][y].second;

        if(dir == 'L'){
          while(c--){
            grp[x][y].second--;
            if(grp[x][y].second==-1)
              grp[x][y].second = 3;
          }
        }else if(dir == 'R'){
          while(c--){
            grp[x][y].second++;
            if(grp[x][y].second==4)
              grp[x][y].second = 0;
          }
        }else if(dir == 'F'){
          grp[x][y].first = 0;
          grp[x][y].second = 0;
          while(c--){
            int nx = x+dx[nowdir];
            int ny = y+dy[nowdir];
            if(0<nx && nx<=a && 0<ny && ny<=b){
              if(grp[nx][ny].first!=0){
                cout << "Robot " << r << " crashes into robot " << grp[nx][ny].first;
                return 0;
              }
            }else{
              cout << "Robot "<< r <<" crashes into the wall";
              return 0;
            }
            x = nx;y=ny;
          }
          grp[x][y].first = r;
          grp[x][y].second = nowdir;
          robots[r].first = x;
          robots[r].second = y;
        }
      }
  
  cout << "OK";
} 