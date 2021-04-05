#include <stdio.h>

long long sol(int m) {
	long long a = 1, b = 1, c = 1, d = 2, e = 2, f;
	if (m == 1 || m == 2 || m == 3) {
		return a;
	}
	else if (m == 4 || m == 5) {
		return d;
	}
	else {
		for (int i = 5; i < m; i++) {
			f = a + e;
			a = b;
			b = c;
			c = d;
			d = e;
			e = f;
		}
		return f;
	}
}

int main() {
	int n, m;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		printf("%lld\n", sol(m));
	}
	return 0;
}