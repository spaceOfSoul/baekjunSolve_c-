#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char key[21];
  char value[21];
  struct Node *next;
} Node;

typedef struct LinkedList {
  Node *head;
  int size;
} LinkedList;

typedef struct hashTable {
  int size;
  int initSize;
  LinkedList *list;
} hashTable;

void hashMap_init(hashTable *);
Node *searchNode(hashTable *, char *);

// hashtable functions
void hashMap_init(hashTable *table) {
  table->initSize = 500;
  table->list = (LinkedList *)malloc(table->initSize * sizeof(LinkedList));
  for (int i = 0; i < table->initSize; i++)
    table->list[i].head = NULL;
  table->size = 0;
}

int hashing(char *str, int table_size) {
  int size = strlen(str);
  int hash = 0;
  for (int i = 0; i < size; i++)
    hash += str[i];
  return hash % table_size;
}

void pushToTable(hashTable *table, char *key, char *value) {
  Node *tmp = (Node *)malloc(sizeof(Node));
  strcpy(tmp->key, key);
  strcpy(tmp->value, value);
  tmp->next = NULL;

  int hash = hashing(key, table->initSize);
  Node *write_node = searchNode(table, key);
  // printf("key :%s hash : %d\n", key, hash);
  if (write_node != NULL) {
    if (!strcmp(write_node->key, key)) {
      strcpy(write_node->value, value);
      free(tmp);
    } else
      write_node->next = tmp;
  } else {
    table->list[hash].head = tmp;
    // printf("val :%s\n", table->list[hash].head->value);
  }
}

Node *searchNode(hashTable *table, char *key) {
  int hash = hashing(key, table->initSize);
  // printf("%d\n", hash);
  if (table->list[hash].head == NULL)
    return NULL;

  Node *tmp = table->list[hash].head;
  while (tmp->next != NULL) {
    if (!strcmp(tmp->key, key))
      return tmp;
    tmp = tmp->next;
  }
  return tmp;
}

char *getFromTable(hashTable *table, char *key) {
  // printf("key : %s\n", key);
  Node *tmp = searchNode(table, key);
  if (tmp == NULL || strcmp(key, tmp->key)) {
    return NULL;
  }
  // printf("%s : %s\n", key, tmp->value);
  return tmp->value;
}

int main(void) {
  int n, m;

  hashTable table;
  hashMap_init(&table);

  scanf("%d %d", &n, &m);

  char address[21];
  char password[21];
  while (n--) {
    scanf("%s %s", address, password);
    pushToTable(&table, address, password);
  }

  // printf("\nfind\n");
  while (m--) {
    scanf("%s", address);
    printf("%s\n", getFromTable(&table, address));
  }
  return 0;
}