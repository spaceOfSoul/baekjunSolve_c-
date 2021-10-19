#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  unsigned int k,n;
  cin >> k >> n;
  unsigned int lens[k];

  for(int i = 0;i<k; i++){
    cin >> lens[i];
  }
  sort(lens, lens + k);
  
  unsigned int first = 1;
  unsigned int last = lens[k-1];
  unsigned int mid;
  unsigned int result = 1;
  unsigned int lines = 0;
  while(first <= last){
    lines = 0;
    mid = (first + last)/2;
    for(int i = 0; i < k; i++){
      lines += lens[i] / mid;
    }

    if(lines < n){
      last = mid-1;
    }else{
      first = mid+1;
      result = max(result, mid);
    }
  }
  cout << result;
}