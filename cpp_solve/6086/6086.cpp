#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int cap[52][52];
int flow[52][52];
int d[52];
vector<int> graph[52];
int result;

void maxfolow(){
  while(true){
    fill(d, d+52, -1);
    queue<int> que;
    que.push(0);
    while(!que.empty()){
      int x = que.front();
      que.pop();
      for(int i:graph[x]){
        if(cap[x][i] - flow[x][i] > 0 && d[i] == -1){
          que.push(i);
          d[i] = x;
          if(i == 25)
            break;
        }
      }
    }
    if(d[25] == -1)
      break;
    int amount = 999999999;
    for(int i=25; i!=0; i=d[i])
      amount = min(amount, cap[d[i]][i] - flow[d[i]][i]);
    
    for(int i=25; i!=0; i=d[i]){
      flow[d[i]][i] += amount;
      flow[i][d[i]] -= amount;
    }
    result+=amount;
  }
}

int change(char a){
  if(a>='a')
    return a-'a'+26;
  return a-'A';
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n;
  char a,b;
  int c;
  while(n--){
    int s,f;
    cin >> a >> b >> c;
    s = change(a);
    f = change(b);
    cap[s][f] += c;
    cap[f][s] += c;
    graph[s].push_back(f);
    graph[f].push_back(s);
  }
  maxfolow();
  cout << result;
} 