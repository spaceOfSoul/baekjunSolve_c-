#include <stdio.h>

void swap(unsigned int *a, unsigned int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(unsigned int *arr, int left, int right) {
  int pl = left;
  int pr = right;

  int mid = arr[(left + right) / 2];

  while (pl <= pr) {
    while (arr[pl] < mid)
      pl++;
    while (arr[pr] > mid)
      pr--;

    if (pl <= pr) {
      swap(arr + pl, arr + pr);
      pl++;
      pr--;
    }
  }
  if (left < pr)
    sort(arr, left, pr);
  if (pl < right)
    sort(arr, pl, right);
}

int main(void) {
  unsigned int k, n;
  unsigned int lens[10000];

  scanf("%d %d", &k, &n);

  for (int i = 0; i < k; i++) {
    scanf("%d", lens + i);
  }
  sort(lens, 0, k - 1);

  unsigned int first = 1;
  unsigned int last = lens[k - 1];
  unsigned int mid;

  unsigned int result = 1;
  unsigned int lines = 0;

  while (first <= last) {
    lines = 0;
    mid = (first + last) / 2;
    for (int i = 0; i < k; i++) {
      lines += lens[i] / mid;
    }

    if (lines < n) {
      last = mid - 1;
    } else {
      first = mid + 1;
      if (mid > result)
        result = mid;
    }
  }
  printf("%d", result);
  return 0;
}