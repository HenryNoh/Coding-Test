#include <stdio.h>

int main(void) {
	int i = 0, num = 0;
	scanf("%d", &num);
	int *arr = (int*)calloc(10, sizeof(int));

	while (num != 0) {//�Է� ���� ���� 0�� �ƴҶ�����
		arr[num % 10]++; //�Է� ���� �� 10���� ���� ������ �ε����� arr++
		num = num / 10; //���� �� 10���� ������

	}

	for (i = 9; i >= 0; i--) {
		while (arr[i] > 0) {
			printf("%d", i);
			arr[i]--;
		}
	}
}