#include <stdio.h>
#include <stdlib.h>

typedef struct que {
  int size;
  unsigned int *arr;
  int (*compare)(int, int);
} priority_que;

void init(priority_que *q, int maxSize, int (*compare)(int, int)) {
  int i = 0;
  q->size = 0;
  q->arr = (unsigned int *)malloc(sizeof(unsigned int) * maxSize * 4);
  q->compare = compare;
  for (i = 0; i < maxSize * 4; i++) {
    q->arr[i] = 0;
  }
}

void swap(unsigned int *a, unsigned int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void push(priority_que *q, int data) {
  q->arr[q->size] = data;

  int now = q->size;

  int parent = (q->size - 1) / 2;
  while (now > 0 && q->compare(q->arr[now], q->arr[parent])) {
    swap(&q->arr[now], &q->arr[parent]);
    now = parent;
    parent = (parent - 1) / 2;
  }

  q->size++;
}

unsigned int pop(priority_que *q) {
  int res = q->arr[0];

  q->size--;

  q->arr[0] = q->arr[q->size];

  int now = 0, left = 1, right = 2;

  int target = now;

  while (left < q->size) {
    if (q->compare(q->arr[left], q->arr[target]))
      target = left;

    if (q->compare(q->arr[right], q->arr[target]) && right < q->size)
      target = right;

    if (target == now)
      break;
    else {
      swap(&q->arr[now], &q->arr[target]);
      now = target;
      left = now * 2 + 1;
      right = now * 2 + 2;
    }
  }
  return res;
}

int is_empty(priority_que *q) { return q->size == 0; }

int compare(int a, int b) { return a > b; }

int main(void) {
  int n;
  scanf("%d", &n);

  priority_que que;
  init(&que, n, compare);

  unsigned int c;
  while (n--) {
    scanf("%u", &c);
    if (!c) {
      if (is_empty(&que))
        printf("0\n");
      else
        printf("%d\n", pop(&que));
    } else
      push(&que, c);
  }
  return 0;
}