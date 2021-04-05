#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b) {
	return (a >= b) ? a : b;
}

int main(void) {
	int num, i, j, max = 0;

	scanf("%d", &num);
	//2개의 2차원 배열 동적할당
	int **arr = (int**)malloc(sizeof(int*)*num);
	int **temp = (int**)malloc(sizeof(int*)*num);

	for (i = 1; i <= num; i++) {
		arr[i] = (int*)malloc(sizeof(int*)*i);
		temp[i] = (int*)malloc(sizeof(int*)*i);
	}

	for (i = 1; i <= num; i++) {
		for (j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//첫 DP배열은 입력받은 배열의 첫번째와 같음
	temp[1][1] = arr[1][1];
	//2번째 부터 DP배열 생성
	for (i = 2; i <= num; i++) {
		for (j = 1; j <= i; j++) {
			if (j == 1) { //삼각형의 제일 왼쪽은 전 DP값과 현재값의 합
				temp[i][j] = temp[i - 1][j] + arr[i][j];
			}
			else if (j == i) { //삼각형의 제일 오른쪽은 전DP값과 현재값의 합
				temp[i][j] = temp[i - 1][j - 1] + arr[i][j];
			}
			else { //삼각형의 중앙부는 위의 두수중 큰것과 현재값의 합
				temp[i][j] = compare(temp[i - 1][j - 1], temp[i - 1][j]) + arr[i][j];
			}
		}
	}
	// 최댓값 구하기
	for (i = 1; i <= num; i++) {
		if (temp[num][i] > max) max = temp[num][i];
	}
	printf("%d ", max);
}