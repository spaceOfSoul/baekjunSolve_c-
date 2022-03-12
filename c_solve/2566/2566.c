#include <stdio.h>
int r,c;
int result;

int main(void) {
  int a;
  for(int i=1; i<=9; i++){
    for(int j=1; j<=9; j++){
      scanf("%d", &a);
      if(a>result){
        result=a;
        r=i;c=j;
      }
    }
  }
  printf("%d\n%d %d",result,r,c);
  return 0;
}