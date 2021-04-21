#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

long DP[101][11]; //100까지 받을수 있고 0~9 까지 10개 이므로 100*10 2차원배열 설정

int compare(int a, int b) {
	return (a <= b) ? a : b;
}

int main(void) {
	int num, i;
	long sum;
	scanf("%d", &num);
	for (i = 1; i <= 9; i++) { //입력 받은 수가 1자리 일 경우 DP의 첫 배열은 1로 초기화
		DP[1][i] = 1;
	}

	for (i = 2; i <= num; i++) { //입력 받은 수가 2자리 이상 일 경우
		DP[i][0] = DP[i - 1][1]; //끝자리가 0인 경우는 이전 DP배열의 1번째와 같음 0은 1로부터만 옴
		for (int j = 1; j <= 9; j++) { // 끝자리가 1~9인 경우 이전 DP배열의 양옆의 합과 같음
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
		}
	}
	sum = 0;

	for (i = 0; i < 10; i++) { //최종 DP배열의 각 자리수 합
		sum += DP[num][i];
	}

	printf("%d\n", sum % 1000000000);
	return 0;
}