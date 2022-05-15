#include <stdio.h>

int main(void) {
	
	int end;
	int num;
	int min= 2147483647, max= -2147483648;
	scanf("%d", &end);

	for (int i = 0; i < end; i++) {
		scanf("%d", &num);
		if (num > max) {
			max = num;
		}
		if (num < min) {
			min = num;
		}

	}
	printf("%d %d", min, max);
  return 0;
}