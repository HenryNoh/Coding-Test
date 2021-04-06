#include <stdio.h>

int sort[1000000] = { 0, };
void merge(int arr[], int s, int middle, int e) {
	int i = s; //�������� �迭�� ù��°�迭 ������
	int j = middle + 1; //�ι�° �迭 ������
	int k = i; // ������ �迭�� ������

	while (i <= middle && j <= e)// �ΰ��� �迭 �� �ϳ��� �迭�� ������������ �ݺ�
	{
		if (arr[i] <= arr[j]) {
			sort[k] = arr[i];
			i++;
		}
		else {
			sort[k] = arr[j];
			j++;
		}
		k++;
	}
	//������ �ϳ��� ���� �����͵� ����
	if (i <= middle) {
		for (int g = i; g <= middle; g++) {
			sort[k] = arr[g];
			k++;
		}
	}
	else {
		for (int g = j; g <= e; g++) {
			sort[k] = arr[g];
			k++;
		}

	}
	// ���ĵ� �迭�� ����
	for (int g = s; g <= e; g++) {
		arr[g] = sort[g];
	}
}

void mergeSort(int a[], int s, int e) {
	if (s < e) {
		//����Լ��� ����
		int middle = (s + e) / 2;
		mergeSort(a, s, middle);
		mergeSort(a, middle + 1, e);
		merge(a, s, middle, e);
	}
}
int main(void) {
	int number;
	scanf("%d", &number);
	int a[number];
	for (int i = 0; i < number; i++) {
		scanf("%d", &a[i]);
	}

	mergeSort(a, 0, number - 1);

	for (int i = 0; i < number; i++) {
		printf("%d\\n", a[i]);
	}
}