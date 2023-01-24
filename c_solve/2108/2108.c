#include <math.h>
#include <stdio.h>

int bindo[8001];

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort(int *arr, int left, int right) {
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
  int n;
  int arr[500000];
  double sum = 0;
  int maxIndex = -1;
  int maxBindoVal = -1;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    sum += arr[i];
    bindo[arr[i] + 4000]++;
  }
  sort(arr, 0, n - 1);
  // for (int i = 0; i < n; i++) {
  //   printf("%d\n", arr[i]);
  // }
  printf("%d\n", (int)round(sum / (double)n));
  printf("%d\n", arr[n / 2]);

  int flag = 0;
  for (int i = 0; i < 8001; i++) {
    if (bindo[i] > maxBindoVal) {
      maxBindoVal = bindo[i];
      maxIndex = i - 4000;
      flag = 1;
    } else if (bindo[i] == maxBindoVal && flag) {
      maxBindoVal = bindo[i];
      maxIndex = i - 4000;
      flag = 0;
    }
  }
  printf("%d\n", maxIndex);
  printf("%d", abs(arr[n - 1] - arr[0]));
  return 0;
}