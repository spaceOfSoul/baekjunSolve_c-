#include <stdio.h>

int n,m;
int result;
int sum;

int main(void) {
  scanf("%d %d", &m, &n);
  int excess =0;
  for(int i=1; i<n; i++){
    if(m<=i*i&&i*i<=n){
      sum += i*i;
      if(!excess){
        result = i*i;
        excess = 1;
      }
    }
  }
  if(!sum){
    printf("%d", -1);
    return 0;
  }
  printf("%d\n%d",sum, result);
  return 0;
}