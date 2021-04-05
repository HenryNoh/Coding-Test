#include <stdio.h>

int compare(int a, int b) {
	return (a > b) ? a : b;
}

int main(void) {
	int num, i, j, result = 0, max = 0;
	int arr[1001] = { 0 };
	int dp[1001] = { 0 };
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 1; i <= num; i++) {
		max = 0; //최종 출력할 수열의 길이 0으로 초기화
		for (j = 0; j < i; j++) { //j가 i까지 탐색하면서
			if (arr[i] > arr[j]) { //j가 현재 i보다 작은 값만 탐색
				if (dp[j] > max) { // 전의 dp값이 현재 최대값은 max보다 크다면
					max = dp[j]; //max에 dp값 저장
				}
			}
		}
		dp[i] = max + 1; // i는 자신보다 작은 값만 탐색했으므로 +1 해준다.
		result = compare(result, dp[i]);
	}
	printf("%d", result);
}