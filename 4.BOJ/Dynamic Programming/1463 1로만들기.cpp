#include <stdio.h>

int DP[1000001];

int compare(int a, int b) {
	return (a <= b) ? a : b;
}

int main(void) {
	int num, i;
	scanf("%d", &num);
	DP[1] = 0;

	for (i = 2; i <= num; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0)
			DP[i] = compare(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0)
			DP[i] = compare(DP[i], DP[i / 3] + 1);
	}

	printf("%d\n", DP[num]);
	return 0;
}