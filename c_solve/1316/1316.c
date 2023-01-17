#include <stdio.h>
#include <string.h>

int n;

char str[100];

int main(void) {
  scanf("%d", &n);
  int result = n;
  char tmp;
  char alphabet[26];
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    for (int j = 0; j < 26; j++) {
      alphabet[j] = 0;
    }

    int size = strlen(str);

    tmp = ' ';
    if (!size) {
      continue;
    } else {
      for (int j = 0; j < size; j++) {
        if (!alphabet[str[j] - 'a']) {
          alphabet[str[j] - 'a'] = 1;
          tmp = str[j];
        } else {
          if (tmp == str[j])
            continue;
          result--;
          break;
        }
      }
    }
  }
  printf("%d", result);
}