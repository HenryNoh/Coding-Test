#include <stdio.h>

int compare(int a, int b) {
	return (a > b) ? a : b;
}

int main(void) {
	int num, i, j, result = 0, max = 0;
	int arr[1001] = { 0 };
	int dp1[1001] = { 0 };
	int dp2[1001] = { 0 };
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 1; i <= num; i++) { //앞에서 뒤 가장 긴 증가하는 부분 수열 찾기
		max = 0;
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp1[j] > max) {
					max = dp1[j];
				}
			}
		}
		dp1[i] = max + 1;
	}

	for (i = num; i > 0; i--) { //뒤에서 앞으로 가장 긴 증가하는 부분 수열 찾기
		max = 0;
		for (j = num; j > i; j--) {
			if (arr[i] > arr[j]) {
				if (dp2[j] > max) {
					max = dp2[j];
				}
			}
		}
		dp2[i] = max + 1;
	}

	for (i = 1; i <= num; i++) { // 각 dp배열을 앞에서 뒤로 탐색하면서
		if (result < dp1[i] + dp2[i] - 1) { // 배열 값의 합산 - 1 이 가장큰 값 찾기
			result = dp1[i] + dp2[i] - 1;
		}
	}

	printf("%d", result);
}