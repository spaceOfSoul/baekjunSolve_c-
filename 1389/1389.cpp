#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int graph[100][100];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m;

  for(int i=0; i<m; i++){
    int a,b;
    cin >> a >> b;
    graph[a-1][b-1] = 1;
    graph[b-1][a-1] = 1;
  }

  for(int i=0; i<n;i++){
    for(int j = 0; j<n;j++){
      for(int k=0; k<n;k++){
        if(graph[j][i] && graph[i][k]){
          if(!graph[j][k])
            graph[j][k] = graph[j][i] + graph[i][k];
          else
            graph[j][k] = min(graph[j][i] + graph[i][k],graph[j][k]);
        }
      }
    }
  }

  int minVal = 999999999;
  int result;
  for(int i=0; i<n; i++){
    int a = 0;
    for(int j =0;j<n;j++){
      a+=graph[i][j];
    }
    if(minVal > a){
      minVal = a;
      result = i;
    }
  }
  cout << result+1;
}