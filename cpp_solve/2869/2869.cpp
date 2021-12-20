#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int a,b,v;
  cin >> a >> b >> v;
  if ((v-a)%(a-b) == 0)
    cout <<(v-a)/(a-b)+1;
  else
    cout <<(v-a)/(a-b)+2;
}