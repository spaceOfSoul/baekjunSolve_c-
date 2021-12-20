#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int t;
bool visited[10000];

string bfs(int a, int b){
  queue<pair<int, string>> que;
  que.push({a,""});
  visited[a] = true;

  while(que.front().first != b){
    int now = que.front().first;
    string nowCommend = que.front().second;
    que.pop();
    int wkp;

    wkp = (now *2)%10000;
    if(!visited[wkp]){
      visited[wkp] = true;
      que.push({wkp,nowCommend+'D'});
    }

    wkp = now-1;
    if (wkp < 0)
      wkp = 9999;
    if(!visited[wkp]){
      visited[wkp] = true;
      que.push({wkp,nowCommend+'S'});
    }

    wkp = (now%1000)*10 + now/1000;
    if(!visited[wkp]){
      visited[wkp] = true;
      que.push({wkp,nowCommend+'L'});
    }

    wkp = now / 10 + (now%10)*1000;
    if(!visited[wkp]){
      visited[wkp] = true;
      que.push({wkp,nowCommend+'R'});
    }
  }
  return que.front().second;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> t;
  for(int test = 0; test < t; test++){
    int a,b;
    cin >> a >> b;
    memset(visited, false, sizeof(visited));
    cout << bfs(a,b)<<"\n";
  }
}