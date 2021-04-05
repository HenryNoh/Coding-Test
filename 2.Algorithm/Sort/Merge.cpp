#include <stdio.h>
#define N 100000
int tempdata[N];

void merge(int data[], int low, int mid, int high) {

	int i = low;
	int j = mid + 1;
	int k = low;
	int idx;

	while (i <= mid && j <= high) {
		if (data[i] < data[j]) {
			tempdata[k++] = data[i++];
		}
		else {
			tempdata[k++] = data[j++];
		}
	}
	if (mid < i) {
		for (idx = j; idx <= high; idx++) {
			tempdata[k++] = data[idx];
		}
	}
	else {
		for (idx = i; idx <= mid; idx++) {
			tempdata[k++] = data[idx];
		}
	}

	for (idx = low; idx <= high; idx++) {
		data[idx] = tempdata[idx];
	}
}

void mergesort(int data[], int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;

		mergesort(data, left, center);
		mergesort(data, center + 1, right);
		merge(data, left, center, right);
	}
}

int main(void) {
	int i, num;

	scanf("%d", &num);

	int array[num];

	for (i = 0; i < num; i++) {
		scanf("%d", &array[i]);
	}

	mergesort(array, 0, num - 1);

	for (i = 0; i < num; i++) {
		printf("%d\n", array[i]);
	}
	return 0;
}