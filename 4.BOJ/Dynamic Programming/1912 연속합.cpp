#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

int compare(int a, int b) {
	return (a > b) ? a : b;
}

int main(void) {
	int num, i, max = -1000, sum = 0;
	int arr[100001] = { 0 };

	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > 0) { //�ش� ���� ����� ���
			if (sum < 0) { //���� �������� ���� ������ ���
				sum = 0; //���ؿ� ���� �ʱ�ȭ�ϰ�
				sum = sum + arr[i]; //���� �����Ѵ�.
			}
			else { //���� �������� ���� ����� ���
				sum = sum + arr[i]; //��� �����ش�.
			}
			max = compare(max, sum); //if(sum<0)�� ��� ���� ���Ѱ��� Ŭ�� �ֱ⿡ �����ش�.
		}
		else { //�ش� ���� ������ ���
			if (sum <= 0) { //���� �������� ���� ������ ���
				max = compare(max, arr[i]); //���� �ʿ� ���� �����ش�.
			}
			else { //���� �������� ���� ����� ���
				sum = sum + arr[i]; //���� ����� ���� �� Ŀ���� �����Ƿ� �ջ길 ���ش�.
			}
		}
	}
	printf("%d", max);
}