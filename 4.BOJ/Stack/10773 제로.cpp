#include <stdio.h>

int main(void) {
	int N, i, j = 0, num, sum = 0;
	int stack[100001] = { 0 };
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num == 0) {
			stack[j] = 0;
			j--;
		}
		else {
			stack[j] = num;
			j++;
		}
	}
	for (i = 0; i < j; i++) {
		sum += stack[i];
	}
	printf("%d", sum);
}