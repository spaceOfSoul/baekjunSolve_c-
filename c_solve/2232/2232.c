#include <stdio.h>
#include <stdlib.h>

typedef struct pair {
  int first;
  int second;
} pair;

int N;
int p[50000];
pair sorted_p[50000];
int pushed_p[50000];
int pushed_p_index;

// pair compare
int compare_pair(pair *a, pair *b) {
  if (a->first < b->first)
    return 1;
  else if (a->first > b->first)
    return -1;
  else
    return 0;
}

// int comapre
int compare_int(const void *first, const void *second) {
  if (*(int *)first > *(int *)second)
    return 1;
  else if (*(int *)first < *(int *)second)
    return -1;
  else
    return 0;
}

void bomb(int index, int power) {
  // out of index or power is weak
  if (index < 0 || index >= N || power <= p[index])
    return;

  if (p[index] != -1) {
    if (index + 1 < N) {
      bomb(index + 1, p[index]);
    }
    if (index - 1 >= 0) {
      bomb(index - 1, p[index]);
    }
    p[index] = -1;
  }
}

int main() {
  scanf("%d", &N);
  int i = 0;
  for (i = 0; i < N; i++) {
    scanf("%d", p + i);
    sorted_p[i].first = p[i];
    sorted_p[i].second = i;
  }

  qsort(sorted_p, N, sizeof(pair),
        (int (*)(const void *, const void *))compare_pair);

  for (i = 0; i < N; i++) {
    if (p[sorted_p[i].second] != -1) {
      bomb(sorted_p[i].second, p[sorted_p[i].second] + 1);
      pushed_p[pushed_p_index++] = sorted_p[i].second + 1;
    }
  }

  qsort(pushed_p, pushed_p_index, sizeof(int),
        (int (*)(const void *, const void *))compare_int);

  for (i = 0; i < pushed_p_index; i++) {
    printf("%d\n", pushed_p[i]);
  }

  return 0;
}