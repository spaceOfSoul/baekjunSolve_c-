#include <iostream>
#include <vector>
using namespace std;

int n;
int net[51][51];
int minscore = 999999999;
vector<int> member;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;

  for(int i= 1;i<=n; i++){
    for(int j=1; j<=n; j++){
      net[i][j] = 999999999;
      if(i==j)
        net[i][j] = 0;
    }
  }
  int a,b;
  while(true){
    cin >> a >> b;
    if(a == -1 && b == -1)
      break;
    net[a][b] = 1;
    net[b][a] = 1;
  }
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      for(int k=1; k<=n; k++)
        if(net[j][k]>net[j][i]+net[i][k])
          net[j][k] = net[j][i]+net[i][k];

  for(int i=1; i<=n; i++){
    int score = 1;
    for(int j=1; j<=n; j++){
      if(net[i][j]>score)
        score = net[i][j];
    }
    if(minscore>score){
      minscore = score;
      member.clear();
      member.push_back(i);
    }else if(minscore == score){
      member.push_back(i);
    }
  }
  cout << minscore << " " << member.size() << "\n";
  for(int i:member){
    cout << i << " ";
  }
} 