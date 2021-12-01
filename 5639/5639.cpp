#include <iostream>
using namespace std;

int arr[10000];
int cur;

void postOrder(int start, int end){
  if(start > end)
    return;

  int parent = arr[start];
  int ptr = start +1;

  for(int i=ptr; i<= end; i++){
    if(arr[i] > parent){
      ptr = i;
      break;
    }
  }
  postOrder(start+1, ptr-1);
  postOrder(ptr, end);
  cout << parent << "\n";
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int a;
  while(cin >> a)
      arr[cur++] = a;
  
  postOrder(0, cur-1);
} 