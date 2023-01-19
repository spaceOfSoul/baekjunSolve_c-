#include <stdio.h>

int n;
int arr[1000000];
int b, c;
long long result;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", arr + i);
  scanf("%d %d", &b, &c);
  result = n;
  for (int i = 0; i < n; i++) {
    arr[i] = arr[i] - b;
    if (arr[i] > 0) {
      result += (arr[i] / c);
      if (arr[i] % c)
        result++;
    }
  }
  printf("%lld", result);
}