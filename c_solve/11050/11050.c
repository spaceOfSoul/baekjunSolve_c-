#include <stdio.h>
int n,k;
int fac(int a){
  int tmp=1;
  for(int i=1; i<=a; i++){
    tmp*=i;
  }
  return tmp;
}
int main(void) {
  scanf("%d %d", &n, &k);
  printf("%d", fac(n)/(fac(n-k)*fac(k)));
  return 0;
}