#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long sol(int m) {
	long long a = 0, b = 1, c; //int 타입의 한계를 잘 생각해서 사용
	for (int i = 1; i < m; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%lld", sol(n));

	return 0;
}