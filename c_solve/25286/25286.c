#include <stdio.h>

int main(void) {
  int t;
  scanf("%d",&t);

  int y, m;
  while(t--){
    scanf("%d %d",&y,&m);
    m--;
    if(m==2){
      if((y%4==0 && y%100!=0) || y%400==0){
        printf("%d %d %d",y,m,29);
      }else{
        printf("%d %d %d",y,m,28);
      }
    }else if(m==4||m==6||m==9||m==11){
      printf("%d %d %d",y,m,30);
    }else{
      if(m==0){
        printf("%d %d %d",y-1,12,31);
      }else{
        printf("%d %d %d",y,m,31);
      }
    }
    printf("\n");
  }
  return 0;
}