#include <stdio.h>
int n;
int a[1000];
int b[1000];
int sum;

int main(void) {
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d", a+i);
  
  for(int i=0; i<n; i++)
    scanf("%d", b+i);

  for(int i=0; i<n; i++)
    sum+=a[i];
  printf("%d\n", sum);
  sum=0;
  for(int i=0; i<n; i++){
    if(!b[i])
      sum+=a[i];
  }
  printf("%d", sum);
  return 0;
}