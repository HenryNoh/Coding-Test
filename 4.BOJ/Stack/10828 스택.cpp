#include <stdio.h>
#include <string.h>

int main(void) {
	int N, i, j = 0, num;
	int stack[10001] = { 0 };
	char str[6];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", str);
		if (strcmp(str, "push") == 0) {
			scanf("%d", &num);
			j++;
			stack[j] = num;
		}
		else if (strcmp(str, "pop") == 0) {
			if (j == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", stack[j]);
				stack[j] = 0;
				j--;
			}
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", j);
		}
		else if (strcmp(str, "empty") == 0) {
			if (j == 0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (strcmp(str, "top") == 0) {
			if (j == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", stack[j]);
			}
		}
	}
}