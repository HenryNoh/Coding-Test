#include <stdio.h>

void QuickSort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}

	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (data[key] >= data[i] && i <= end) { //data[key] <= data[i] 이고
			i++;
		}
		while (data[key] <= data[j] && j > start) { //data[key] >= data[j] 이면 내림차순정렬
			j--;
		}
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	QuickSort(data, start, j - 1);
	QuickSort(data, j + 1, end);
}

int main(void) {
	int i, number = 10;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };

	QuickSort(array, 0, number - 1);

	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);

	}
	return 0;
}