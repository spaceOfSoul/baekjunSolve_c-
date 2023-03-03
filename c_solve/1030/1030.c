#include <math.h>
#include <stdio.h>

int n, k, size;

int output(int r, int c, int pn) {
  if (pn == 1)
    return 0;

  int squre_size = pn / n;
  int lyb = n - k;
  int ryb = n + k;

  if (lyb * squre_size / 2 <= r && r < ryb * squre_size / 2 &&
      lyb * squre_size / 2 <= c && c < ryb * squre_size / 2)
    return 1;

  return output(r % squre_size, c % squre_size, squre_size);
}

int main(void) {
  int s, r1, r2, c1, c2;
  scanf("%d %d %d %d %d %d %d", &s, &n, &k, &r1, &r2, &c1, &c2);

  size = (int)pow(n, s);

  for (int i = r1; i <= r2; i++) {
    for (int j = c1; j <= c2; j++) {
      printf("%d", output(i, j, size));
    }
    printf("\n");
  }
  return 0;
}