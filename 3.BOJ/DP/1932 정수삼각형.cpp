#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b) {
	return (a >= b) ? a : b;
}

int main(void) {
	int num, i, j, max = 0;

	scanf("%d", &num);
	//2���� 2���� �迭 �����Ҵ�
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
	//ù DP�迭�� �Է¹��� �迭�� ù��°�� ����
	temp[1][1] = arr[1][1];
	//2��° ���� DP�迭 ����
	for (i = 2; i <= num; i++) {
		for (j = 1; j <= i; j++) {
			if (j == 1) { //�ﰢ���� ���� ������ �� DP���� ���簪�� ��
				temp[i][j] = temp[i - 1][j] + arr[i][j];
			}
			else if (j == i) { //�ﰢ���� ���� �������� ��DP���� ���簪�� ��
				temp[i][j] = temp[i - 1][j - 1] + arr[i][j];
			}
			else { //�ﰢ���� �߾Ӻδ� ���� �μ��� ū�Ͱ� ���簪�� ��
				temp[i][j] = compare(temp[i - 1][j - 1], temp[i - 1][j]) + arr[i][j];
			}
		}
	}
	// �ִ� ���ϱ�
	for (i = 1; i <= num; i++) {
		if (temp[num][i] > max) max = temp[num][i];
	}
	printf("%d ", max);
}