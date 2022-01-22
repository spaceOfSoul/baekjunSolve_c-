#include <iostream>
#include <string>
using namespace std;

int n,m;
bool props[26][26];

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  
  cin.ignore();
  string prop;
  for(int i=0; i<n; i++){
    getline(cin,prop);
    props[prop[0]-'a'][prop[5]-'a'] = true;
  }

  for(int i=0; i<26; i++){
    for(int j=0; j<26; j++){
      for(int k=0; k<26; k++){
        if(props[j][i] && props[i][k])
          props[j][k] = true;
      }
    }
  }   
  cin >> m;
  cin.ignore();
  
  while(m--){
    getline(cin,prop);
    if(props[prop[0]-'a'][prop[5]-'a'])
      cout << 'T';
    else
      cout << 'F';
    cout << "\n";
  }
} 