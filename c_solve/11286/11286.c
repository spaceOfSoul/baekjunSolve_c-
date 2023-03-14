#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ele {
  long long val;
  long long absolute;
} ele;

ele make_ele(long long a, long long b) {
  ele tmp = {a, b};
  return tmp;
}

typedef struct que {
  int size;
  ele *arr;
  int (*compare)(ele, ele);
} priority_que;

void init(priority_que *q, int maxSize, int (*compare)(ele, ele)) {
  int i = 0;
  q->size = 0;
  q->arr = (ele *)malloc(sizeof(ele) * maxSize * 4);
  q->compare = compare;
  for (i = 0; i < maxSize * 4; i++) {
    q->arr[i] = make_ele(0, 0);
  }
}

void swap(ele *a, ele *b) {
  ele temp = *a;
  *a = *b;
  *b = temp;
}

void push(priority_que *q, ele data) {
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

ele pop(priority_que *q) {
  ele res = q->arr[0];

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

int compare(ele a, ele b) {
  if (a.absolute < b.absolute) {
    return 1;
  } else if (a.absolute == b.absolute) {
    if (a.val < b.val)
      return 1;
    return 0;
  }
  return 0;
}

int main(void) {
  int n;
  scanf("%d", &n);

  priority_que que;
  init(&que, n, compare);

  long long c;
  while (n--) {
    scanf("%lld", &c);
    if (!c) {
      if (is_empty(&que))
        printf("0\n");
      else
        printf("%lld\n", pop(&que).val);
    } else
      push(&que, make_ele(c, abs((int)c)));
  }
  return 0;
}