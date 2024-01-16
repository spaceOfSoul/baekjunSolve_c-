#include <stdio.h>

int n, m;

int arr[20000002];

int main() {
  scanf("%d", &n);

  int val;
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    arr[val + 10000000] = 1;
  }

  scanf("%d", &m);

  while (m--) {
    scanf("%d", &val);
    printf("%d ", arr[val + 10000000]);
  }
}