#include <stdio.h>

void reflect_array(int (*arr)[20], int (*result)[20], char dir, int n);

int main(void) {
  int n;
  char dir;
  int arr[20][20];
  int result[20][20];
  scanf("%c %d", &dir, &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  reflect_array(arr,result,dir,n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(result[i][j] == 1 || result[i][j] == 8){
        printf("%d ",result[i][j]);
      }else if(result[i][j] ==2){
        printf("%d ",5);
      }else if(result[i][j] == 5){
        printf("%d ",2);
      }else{
        printf("? ");
      }
    }
    printf("\n");
  }
  return 0;
}

void reflect_array(int (*arr)[20], int (*result)[20],char dir, int n){
  if(dir == 'L'||dir == 'R'){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        result[i][n-1-j] = arr[i][j];
      }
    }
  }
  else if(dir == 'U'||dir == 'D'){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        result[n-1-i][j] = arr[i][j];
      }
    }
  }
}