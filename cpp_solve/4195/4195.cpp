#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int t;
int parents[200000];
int networkSize[200000];

int findparents(int a){
  if(parents[a] == a) return a;
  return parents[a] = findparents(parents[a]);
}

void union_relationShip(int a, int b){
  a = findparents(a);
  b = findparents(b);

  if(a!=b){
    if(networkSize[a] > networkSize[b]){
      parents[b] = a;
      networkSize[a] += networkSize[b];
    }else{
      parents[a] = b;
      networkSize[b] += networkSize[a];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> t;
  while(t--){
    int f;
    cin >> f;
    map<string, int> friendsList;
    int setNum = 0;

    for(int i = 0; i<2*f; i++){
      parents[i] = i;
      networkSize[i] = 1;
    }
    
    for(int i = 0; i< f; i++){
      string fr1,fr2;
      cin >> fr1 >> fr2;
      if(friendsList.find(fr1) == friendsList.end())
        friendsList[fr1] = setNum++;
      if(friendsList.find(fr2) == friendsList.end())
        friendsList[fr2] = setNum++;
      
      union_relationShip(friendsList[fr1],friendsList[fr2]);
      cout << max(networkSize[parents[friendsList[fr1]]], networkSize[parents[friendsList[fr2]]]) << "\n";
    }
  }
} 