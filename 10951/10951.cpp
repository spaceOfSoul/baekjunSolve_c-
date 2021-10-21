#include <iostream>
int main() {
  while(true){
    int a,b;
    if(scanf("%d %d",&a,&b) != EOF)
      printf("%d\n",a+b);
    else
      break;
  }
}