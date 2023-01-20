#include <stdio.h>
#include <stdlib.h>

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
  dq->size -= 1;
  free(tmp);
}

void pop_r(deque *dq) {
  node *tmp = dq->right;
  dq->right = tmp->pre;
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

void card_add_together(deque *player, deque *ground) {
  int ground_size = ground->size;
  while (ground_size--) {
    push_l(player, left(ground).var);
    pop_l(ground);
  }
}

int main(void) {
  int n, m;
  deque do_deck, su_deck, ground_do, ground_su;
  char winner = 0; // 1 : do win, 2 : su win
  char turn = 1;
  init(&do_deck);
  init(&su_deck);
  init(&ground_do);
  init(&ground_su);

  scanf("%d %d", &n, &m);
  while (n--) {
    int a, b;
    scanf("%d %d", &a, &b);

    push_r(&do_deck, a);
    push_r(&su_deck, b);
  }

  while (m--) {
    if (turn == 1) {
      push_r(&ground_do, right(&do_deck).var);
      pop_r(&do_deck);
    } else {
      push_r(&ground_su, right(&su_deck).var);
      pop_r(&su_deck);
    }
    if (is_empty(&do_deck) || is_empty(&su_deck))
      break;
    if (!is_empty(&ground_do) && !is_empty(&ground_su) &&
        (right(&ground_do).var + right(&ground_su).var == 5)) {
      card_add_together(&su_deck, &ground_do);
      card_add_together(&su_deck, &ground_su);
    } else if (!is_empty(&ground_do) && right(&ground_do).var == 5 ||
               !is_empty(&ground_su) && right(&ground_su).var == 5) {
      card_add_together(&do_deck, &ground_su);
      card_add_together(&do_deck, &ground_do);
    }
    turn *= -1;
  }

  if (do_deck.size < su_deck.size) {
    printf("su");
  } else if (do_deck.size > su_deck.size) {
    printf("do");
  } else {
    printf("dosu");
  }
  return 0;
}