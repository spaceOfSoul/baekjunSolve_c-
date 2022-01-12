#include <iostream>
#include <string>
using namespace std;

int n;
int arr[9];
int result;

int main() {
  cin >> n;
  string a = to_string(n);
  for(int i=0; i<a.size(); i++){
    int b = a[i]-'0';
    if(b==6||b==9)
      arr[6]++;
    else
      arr[b]++;
  }
  if(arr[6]%2 == 1)
    arr[6]=arr[6]/2+1;
  else
    arr[6]/=2;
  for(int i=0; i<9; i++){
    if(arr[i]>result)
      result = arr[i];
  }
  cout << result;
} 