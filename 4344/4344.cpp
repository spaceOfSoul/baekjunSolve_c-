#include <iostream>
#include <cmath> 
using namespace std;

float scores[1000];
int t;
int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  cout << fixed;
  cout.precision(3);
  cin >> t;

  while(t--){
    int students;
    float sum = 0;
    cin >> students;
    for(int i=0; i< students; i++){
      cin >> scores[i];
      sum += scores[i];
    }

    float stan =sum/students;
    int numer = 0;
    for(int i=0; i<students; i++){
      if(scores[i] > stan)
        numer++;
    }
    cout << ((float)numer / (float)students) * 100 << "%"<< "\n";
  }
} 