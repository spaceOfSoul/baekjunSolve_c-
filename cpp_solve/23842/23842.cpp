#include <iostream>
using namespace std;

int num[10] = {6,2,5,5,4,5,6,3,7,6};
int n;
int main() {
  cin >> n;
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
        for(int k=0; k<10; k++){
          for(int l=0; l<10; l++){
            int hap = (i*10+j)+(k*10+l);
            if(num[i]+num[j]+num[k]+num[l]+num[hap%10]+num[hap/10] == n-4 && hap<100){
              cout << i << j << "+" << k<<l<<"="<<hap/10 << hap%10;
              return 0;
            }
          }
        }
      }
    }
  cout << "impossible";
} 