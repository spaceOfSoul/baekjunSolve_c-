#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int var;
  struct node *pre;
  struct node *next;
} node;

typedef struct deque {
  node *left;
  node *right;
  int size;
} deque;

void init(deque *dq) {
  dq->right = NULL;
  dq->left = NULL;
  dq->size = 0;
}

int is_empty(deque *dq) { return (dq->size == 0); }

void push_r(deque *dq, int var) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->var = var;

  if (is_empty(dq)) {
    dq->right = new_node;
    dq->left = new_node;
    new_node->pre = NULL;
    new_node->next = NULL;
  } else {
    node *tmp = dq->right;
    dq->right = new_node;
    new_node->pre = tmp;
    tmp->next = new_node;
    new_node->next = NULL;
  }
  dq->size += 1;
}

void push_l(deque *dq, int var) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->var = var;

  if (is_empty(dq)) {
    dq->left = new_node;
    dq->right = new_node;
    new_node->pre = NULL;
    new_node->next = NULL;
  } else {
    node *tmp = dq->left;
    dq->left = new_node;
    new_node->next = tmp;
    tmp->pre = new_node;
    new_node->pre = NULL;
  }
  dq->size += 1;
}

void pop_l(deque *dq) {
  node *tmp = dq->left;
  dq->left = tmp->next;
  // dq->left->pre = NULL;
  dq->size -= 1;
  free(tmp);
}

void pop_r(deque *dq) {
  node *tmp = dq->right;
  dq->right = tmp->pre;
  // dq->right->next = NULL;
  dq->size -= 1;
  free(tmp);
}

void pop_all(deque *dq) {
  while (!is_empty(dq)) {
    pop_l(dq);
  }
}

node left(deque *dq) { return *(dq->left); }

node right(deque *dq) { return *(dq->right); }

int main(void) {
  int t;
  char functions[400001];
  char arr[1400000];
  char tmp_num[3];
  int n;
  int arr_num[400001];

  deque dq;
  init(&dq);

  scanf("%d", &t);

  while (t--) {
    init(&dq);
    scanf("%s", functions);
    scanf("%d", &n);
    scanf("%s", arr);

    int ptr = 0;
    int arr_size = 0;

    int arrStr_size = strlen(arr);

    int err = 0;
    int reverse = 1;

    for (int i = 0; i < arrStr_size; i++) {
      if ('0' <= arr[i] && arr[i] <= '9') {
        tmp_num[ptr++] = arr[i];
      } else {
        if (ptr) {
          arr_num[arr_size++] = atoi(tmp_num);
          // printf("%d", arr[arr_size - 1]);
          for (int j = 0; j < ptr; j++) {
            tmp_num[j] = '\0';
          }
          ptr = 0;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      push_r(&dq, arr_num[i]);
    }

    int commend_size = strlen(functions);
    for (int i = 0; i < commend_size; i++) {
      if (functions[i] == 'R') {
        reverse *= -1;
      } else {
        if (!is_empty(&dq)) {
          if (reverse == 1)
            pop_l(&dq);
          else
            pop_r(&dq);
        } else {
          err = 1;
          break;
        }
      }
    }

    if (err) {
      printf("error\n");
      pop_all(&dq);
    } else {
      printf("[");
      while (!is_empty(&dq)) {
        if (reverse == 1) {
          printf("%d", left(&dq).var);
          pop_l(&dq);
          if (!is_empty(&dq))
            printf(",");
        } else {
          printf("%d", right(&dq).var);
          pop_r(&dq);
          if (!is_empty(&dq))
            printf(",");
        }
      }
      printf("]\n");
    }
  }
  return 0;
}