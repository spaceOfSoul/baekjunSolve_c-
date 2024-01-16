#include <stdio.h>

int main(void) {
  int n, a, b, c;
  scanf("%d", &n);
  scanf("%d %d %d", &a, &b, &c);

  a = (n - a >= 0) ? a : n;
  b = (n - b >= 0) ? b : n;
  c = (n - c >= 0) ? c : n;
  printf("%d", a + b + c);
  return 0;
}