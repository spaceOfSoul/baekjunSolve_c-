#include <iostream>
#include <cmath>
using namespace std;
int result;
void hanoi(int n, int from,int suport , int pos){
  if(n==1){
    cout << from << " " << pos<<"\n";
  }
  else{
    hanoi(n-1,from,pos,suport);
    cout << from << " " << pos << "\n";
    hanoi(n-1, suport, from, pos);
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int n;
  cin >> n;

  cout << (int)pow(2,n)-1<<"\n";
  hanoi(n,1,2,3);
} 