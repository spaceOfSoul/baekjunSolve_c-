#include <stdio.h>
#include <string.h>

char str[101];

int pel(char *str,int len){
  for(int i=0; i<len/2; i++){
    if(str[i] != str[len-i-1]){
      return 0;
    }
  }
  return len;
}

int main(void) {
  scanf("%s", str);
  int len = strlen(str);
  if(pel(str, len)){
    printf("%d", len);
    return 0;
  }else{
    for(int i=1; i<len; i++){
      int pelen = pel(str+i, len-i);
      if(pelen){
        printf("%d", len+len-pelen);
        return 0;
      }
    }
  }
}