#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool prime[10000];
int visited[10000];

int t, a, b;

int bfs(){
  queue<int> que;
  que.push(a);
  visited[a] = 1;

  while(!que.empty()){
    int now = que.front();
    int step = now;
    que.pop();
    if(now == b)
      return visited[b]-1;

    int jarit[4];//1234
    for(int i=0; i<4; i++){
      jarit[i] = now%10;
      now /=10;
    }

    for(int i=0; i<4; i++){
      for(int j=0; j<10; j++){
        int original = jarit[i];
        if(i==3 && j==0)
          continue;
        jarit[i] = j;
        int num=jarit[3]*1000+jarit[2]*100+jarit[1]*10+jarit[0];
        if(!prime[num] && !visited[num]){
          visited[num] = visited[step] + 1;
          que.push(num);
        }
        jarit[i] = original;
      }
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  for(int i=2; i<10000; i++){
    if(prime[i]) continue;
    for(int j = i+i; j < 10000; j+=i){
      prime[j] = true;
    }
  }
  cin >> t;
  while(t--){
    cin >> a >> b;
    cout << bfs() << "\n";
    for(int i=999; i<10000; i++)
      visited[i] = 0;
  }
} 