#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  double var;
  struct node *pre;
} node;

typedef struct stack {
  node *top;
  int size;
} stack;

void init(stack *s) {
  s->top = NULL;
  s->size = 0;
}

void push(stack *s, double var) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->var = var;
  s->size += 1;

  node *tmp = s->top;
  s->top = new_node;
  new_node->pre = tmp;
}

void pop(stack *s) {
  node *tmp = s->top;
  s->top = tmp->pre;
  s->size -= 1;
  free(tmp);
}

node top(stack *s) { return *(s->top); }

int main(void) {
  int numbers[26];
  int n;
  char str[100];

  scanf("%d", &n);
  scanf("%s", str);

  for (int i = 0; i < n; i++)
    scanf("%d", numbers + i);

  stack stk;
  init(&stk);

  for (int i = 0; i < strlen(str); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z')
      push(&stk, numbers[str[i] - 'A']);
    else {
      double a = top(&stk).var;
      pop(&stk);

      double b = top(&stk).var;
      pop(&stk);

      if (str[i] == '+')
        push(&stk, b + a);
      else if (str[i] == '-')
        push(&stk, b - a);
      else if (str[i] == '*')
        push(&stk, b * a);
      else if (str[i] == '/')
        push(&stk, b / a);
    }
  }
  printf("%.2lf", top(&stk).var);

  return 0;
}