#include <stdio.h>

int A[100][100];
int B[100][100];
int result[100][100];

int main() {
  int n, m, k;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  scanf("%d %d", &m, &k);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < k; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      for (int l = 0; l < m; l++) {
        result[i][j] += A[i][l] * B[l][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }
  return 0;
}