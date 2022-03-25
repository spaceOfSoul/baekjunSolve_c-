#include <stdio.h>
#include <string.h>

char str[100000000];
int cnt;

int main(void) {
  gets(str);

  char *ptr = strtok(str, " ");
  while(ptr != NULL){
      cnt++;
      ptr = strtok(NULL, " ");        
  }

  printf("%d", cnt);
  return 0;
}