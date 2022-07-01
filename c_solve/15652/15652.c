#include <stdio.h>

int n,m;
int arr[8];

void print(int depth, int chose){
  if(depth == m){
    for(int i=0; i<m; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }

  for(int i = chose; i<=n; i++){
    arr[depth] = i;
    print(depth+1, i);
  }
}

int main(void) {
  scanf("%d %d", &n, &m);

  print(0,1);
  return 0;
}