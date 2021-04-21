#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

void fibo(int num) {
	long long a = 0, b = 1, c;
	if (num == 0) {
		printf("1 0\n");
	}
	else if (num == 1) {
		printf("0 1\n");
	}
	else {
		for (int i = 1; i < num; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		printf("%lld %lld\n", a, b);
	}
}

int main(void) {
	int i, num, test;
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &test);
		fibo(test);
	}
}