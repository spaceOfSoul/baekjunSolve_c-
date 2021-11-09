#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[500000];
int howMany[8001];
double sum;

int main() {
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  cin >> n;
  for(int i=0; i< n; i++){
    cin >> arr[i];
    sum += arr[i];
    howMany[arr[i] + 4000]++;
  }
  sort(arr, arr+n);
  cout << round(sum/(double)n) << "\n";
  cout << arr[n/2] << "\n" ;

  int maxBindo = *max_element(howMany, howMany + 8001);

  int count = 0;
  int result = 0;
  for(int i=0; i<= 8000; i++){
    if(count == 2)
      break;
    if(howMany[i] == maxBindo){
      count++;
      result = i-4000;
    }
  }
  cout << result << "\n";
  cout << abs(arr[n-1]-arr[0]);
} 