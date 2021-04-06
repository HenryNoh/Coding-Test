#include <stdio.h>

int compare(int a, int b) {
	return (a >= b) ? b : a;
}

int main(void) {
	int num, i, min = 0;
	int arr[1000][3]; //입력받은 배열
	int temp[1000][3]; //DP할 배열
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	//DP 배열의 첫줄에는 입력받은거 그대로
	temp[0][0] = arr[0][0];
	temp[0][1] = arr[0][1];
	temp[0][2] = arr[0][2];

	// i번째 DP배열의 a번은 i-1번째 DP배열 b,c번중 큰것과 현 배열 a번의 합  
	for (i = 1; i < num; i++) {
		temp[i][0] = compare(temp[i - 1][1], temp[i - 1][2]) + arr[i][0];
		temp[i][1] = compare(temp[i - 1][0], temp[i - 1][2]) + arr[i][1];
		temp[i][2] = compare(temp[i - 1][0], temp[i - 1][1]) + arr[i][2];
	}
	// 셋 중 가장 작은 것 출력
	min = compare(temp[num - 1][0], temp[num - 1][1]);
	if (min < temp[num - 1][2]) printf("%d", min);
	else printf("%d", temp[num - 1][2]);
}