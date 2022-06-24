#include <stdio.h>

int main(void) {
  int t;
  scanf("%d", &t);
  double h, g, BMI;
  while(t--){
    scanf("%lf %lf",&h, &g);
    h/=100;
    BMI = g/(h*h);
    if(h<1.401){
      printf("6");
    }else if(h<1.46){
      printf("5");
    }else if(h<1.59){
      printf("4");
    }else if(h < 1.61){
      if(16.0<=BMI&&BMI<35.0){
        printf("3");
      }else{
        printf("4");
      }
    }else if(h < 2.04){
      if(20.0<=BMI&&BMI<25.0){
        printf("1");
      }else if(18.5<=BMI&&BMI<30.0){
        printf("2");
      }else if(16.0<=BMI&&BMI<35.0){
        printf("3");
      }else{
        printf("4");
      }
    }else{
      printf("4");
    }
    printf("\n");
    
  }
  return 0;
}