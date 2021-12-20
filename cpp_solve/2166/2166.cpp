#include <iostream>
using namespace std;

int n;
pair<double, double> vertex[100001];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  double x,y;
  for(int i=0; i<n; i++)
    cin >> vertex[i].first >> vertex[i].second;
  
  vertex[n] = vertex[0];
  double a = 0;
  double b = 0;
  for(int i=0; i<n; i++){
    a += vertex[i].first * vertex[i+1].second;
    b += vertex[i+1].first * vertex[i].second;
  }
  
  cout << fixed;
  cout.precision(1);
  cout << abs(a-b)/2;
} 