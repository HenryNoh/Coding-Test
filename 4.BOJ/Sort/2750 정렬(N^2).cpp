#include <stdio.h>

int main() {
	int i = 0, j = 0, a, b, temp;
	int arr[1001] = { 0 };

	scanf("%d", &a);

	b = a;

	while (i < a) {
		scanf("%d", &arr[i]);
		i++;
	}

	while (j < b) { //삽입정렬
		i = 0;
		while (i < b - 1) {
			if (arr[i] > arr[i + 1]) { //현재가 다음보다 크면 자리바꿈 O(n^2)
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
			i++;
		}
		b--;
	}

	i = 0;
	while (i < a) {
		printf("%d\n", arr[i]);
		i++;
	}

	return 0;
}

#include <stdio.h>

int main(int argc, char* argv[]) {
	int i, j, num, min, idx = 0, temp;
	int arr[1001] = { 0 };
	scanf_s("%d", &num);

	for (i = 0; i < num; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (i = 0; i < num; i++) { //선택 정렬
		min = 9999;
		for (j = i; j < num; j++) {
			if (min > arr[j]) {
				min = arr[j];
				idx = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[idx];
		arr[idx] = temp;
	}
	for (i = 0; i < num; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}

#include <stdio.h>

int main() {
	int i = 0, j = 0, num, temp;
	int arr[1001] = { 0 };

	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		scanf_s("%d", &arr[i]);
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < num - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < num; i++) {
		printf("%d\n", arr[i]);

	}

	return 0;
}

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
	int i, num;
	int arr[1001] = { 0 };

	scanf_s("%d", &num);
	for (i = 0; i < num; i++) {
		scanf_s("%d", &arr[i]);
	}

	QuickSort(arr, 0, num - 1);

	for (i = 0; i < num; i++) {
		printf("%d\n", arr[i]);

	}
	return 0;
}