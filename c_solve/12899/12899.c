#include <stdio.h>

int n;
int tree[12000000];
const int max = 2000000;

void add(int s, int e, int index, int node) { // update
  // printf("%d %d\n", s, e);
  if (s <= index && index <= e) {
    tree[node]++;
    if (s == e) {
      return;
    }
    int mid = (s + e) / 2;
    add(s, mid, index, node * 2);
    add(mid + 1, e, index, node * 2 + 1);
  }
}

int pop(int s, int e, int index, int node) {
  tree[node]--;
  if (s == e)
    return s;
  int mid = (s + e) / 2;

  if (tree[node * 2] >= index)
    return pop(s, mid, index, node * 2);
  else
    return pop(mid + 1, e, index - tree[node * 2], node * 2 + 1);
}

int main(void) {
  scanf("%d", &n);

  int q, a;
  while (n--) {
    scanf("%d %d", &q, &a);

    if (q == 1) {
      a--;

      add(0, max, a, 1);
    } else {
      printf("%d\n", pop(0, max, a, 1) + 1);
    }
  }
  return 0;
}