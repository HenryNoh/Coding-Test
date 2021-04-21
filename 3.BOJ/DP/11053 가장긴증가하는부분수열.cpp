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
		max = 0; //���� ����� ������ ���� 0���� �ʱ�ȭ
		for (j = 0; j < i; j++) { //j�� i���� Ž���ϸ鼭
			if (arr[i] > arr[j]) { //j�� ���� i���� ���� ���� Ž��
				if (dp[j] > max) { // ���� dp���� ���� �ִ밪�� max���� ũ�ٸ�
					max = dp[j]; //max�� dp�� ����
				}
			}
		}
		dp[i] = max + 1; // i�� �ڽź��� ���� ���� Ž�������Ƿ� +1 ���ش�.
		result = compare(result, dp[i]);
	}
	printf("%d", result);
}