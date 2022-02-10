#include <iostream>
#include <algorithm>
using namespace std;

int l,c;
char arr[15];
char result[15];
bool visited[15];

void password(int count,int now){
  if(count == l){
    int aeiou = 0;
    int ja = 0;
    
    for(int i=0; i<l; i++){
      if(result[i]=='a'||result[i]=='e'||result[i]=='i'||
        result[i]=='o'||result[i]=='u')
        aeiou++;
      else{
        ja++;
      }
    }
    if(!aeiou|| ja<2)
      return;

    for(int i=0; i<l; i++)
      cout << result[i];
    cout << "\n";
    return;
  }

  for(int i=now; i<c; i++){
    if(visited[i])
      continue;
    visited[i] = true;
    result[count] = arr[i]; 
    password(count+1,i);
    visited[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> l >> c;
  for(int i=0; i<c; i++){
    cin >> arr[i];
  }
  sort(arr, arr+c);
  password(0,0);
}