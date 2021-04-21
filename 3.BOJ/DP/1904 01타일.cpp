#include <stdio.h>

void fibo(int num) {
	long long a = 1, b = 1, c;
	for (int i = 1; i < num; i++) {
		c = (a + b) % 15746;
		a = b;
		b = c;
	}
	printf("%lld", b);
}

int main(void) {
	int num;
	scanf("%d", &num);
	fibo(num);
}