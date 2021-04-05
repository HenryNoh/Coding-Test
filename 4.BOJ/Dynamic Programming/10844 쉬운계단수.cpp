#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

long DP[101][11]; //100���� ������ �ְ� 0~9 ���� 10�� �̹Ƿ� 100*10 2�����迭 ����

int compare(int a, int b) {
	return (a <= b) ? a : b;
}

int main(void) {
	int num, i;
	long sum;
	scanf("%d", &num);
	for (i = 1; i <= 9; i++) { //�Է� ���� ���� 1�ڸ� �� ��� DP�� ù �迭�� 1�� �ʱ�ȭ
		DP[1][i] = 1;
	}

	for (i = 2; i <= num; i++) { //�Է� ���� ���� 2�ڸ� �̻� �� ���
		DP[i][0] = DP[i - 1][1]; //���ڸ��� 0�� ���� ���� DP�迭�� 1��°�� ���� 0�� 1�κ��͸� ��
		for (int j = 1; j <= 9; j++) { // ���ڸ��� 1~9�� ��� ���� DP�迭�� �翷�� �հ� ����
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
		}
	}
	sum = 0;

	for (i = 0; i < 10; i++) { //���� DP�迭�� �� �ڸ��� ��
		sum += DP[num][i];
	}

	printf("%d\n", sum % 1000000000);
	return 0;
}