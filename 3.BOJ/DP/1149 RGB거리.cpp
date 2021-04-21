#include <stdio.h>

int compare(int a, int b) {
	return (a >= b) ? b : a;
}

int main(void) {
	int num, i, min = 0;
	int arr[1000][3]; //�Է¹��� �迭
	int temp[1000][3]; //DP�� �迭
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	//DP �迭�� ù�ٿ��� �Է¹����� �״��
	temp[0][0] = arr[0][0];
	temp[0][1] = arr[0][1];
	temp[0][2] = arr[0][2];

	// i��° DP�迭�� a���� i-1��° DP�迭 b,c���� ū�Ͱ� �� �迭 a���� ��  
	for (i = 1; i < num; i++) {
		temp[i][0] = compare(temp[i - 1][1], temp[i - 1][2]) + arr[i][0];
		temp[i][1] = compare(temp[i - 1][0], temp[i - 1][2]) + arr[i][1];
		temp[i][2] = compare(temp[i - 1][0], temp[i - 1][1]) + arr[i][2];
	}
	// �� �� ���� ���� �� ���
	min = compare(temp[num - 1][0], temp[num - 1][1]);
	if (min < temp[num - 1][2]) printf("%d", min);
	else printf("%d", temp[num - 1][2]);
}