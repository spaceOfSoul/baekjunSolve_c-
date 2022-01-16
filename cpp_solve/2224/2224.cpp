#include <iostream>
#include <string>
using namespace std;

int n;
int count;
string prop;
bool propositions[52][52];

int changeIndex(char a){
  if(a > 'Z')
    return a-'a'+26;
  return a-'A';
}

char changeChar(int a){
  if(a<26)
    return a+'A';
  return a+'A'+6;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cin >>n;
  cin.ignore();
  for(int i=0; i<n; i++){
    getline(cin,prop);
    if(prop[0]==prop[5] || propositions[changeIndex(prop[0])][changeIndex(prop[5])])
      continue;
    count++;
    propositions[changeIndex(prop[0])][changeIndex(prop[5])] = true;
  }
  for(int i=0; i<52; i++){
    for(int j=0; j<52; j++){
      for(int k=0; k<52; k++){
        if(propositions[j][k])
          continue;
        if(propositions[j][i] && propositions[i][k] && j!=k){
          propositions[j][k] = true;
          count++;
        }
      }
    }
  }
  cout << count << "\n";
  for(int i=0; i<52; i++){
    for(int j=0; j<52; j++){
      if(propositions[i][j])
        cout << changeChar(i) << " => " << changeChar(j) << "\n";
    }
  }
} 