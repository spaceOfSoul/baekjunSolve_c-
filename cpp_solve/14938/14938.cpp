#include <iostream>
#define INF 1e9
using namespace std;

int n,m,r;
int arr[100];
int dist[100][100];
int count, result;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >> n >> m >> r;

  for(int i=0; i<n; i++)
    cin >> arr[i];
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i==j)
        continue;
      dist[i][j] = INF;
    }
  }

  int a, b, c;
  for(int i=0; i<r; i++){
    cin >> a>>b>>c;
    a--;b--;
    dist[a][b] = c;
    dist[b][a] = c;
  }

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      for(int k=0; k<n;k++)
        if(dist[j][k] > dist[j][i]+dist[i][k])
          dist[j][k] = dist[j][i]+dist[i][k];
      
  for(int i=0; i<n; i++){
    count = arr[i];
    for(int j=0; j<n;j++){
      if(i!=j && dist[i][j] <=m)
        count+=arr[j];
    }
    if(count > result)
      result = count;
  }
  cout << result;
}