#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b) {
	return (a >= b) ? a : b;
}

int main(void) {
	int num, i;

	scanf("%d", &num);
	
	int* arr = (int*)malloc(sizeof(int*) * num);
	int* temp = (int*)malloc(sizeof(int*) * num);

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	temp[0] = arr[0];
	temp[1] = compare(arr[0] + arr[1], arr[1]);
	temp[2] = compare(arr[0] + arr[2], arr[1] + arr[2]);

	for (i = 3; i < num; i++) {
		temp[i] = compare(temp[i - 2] + arr[i], temp[i - 3] + arr[i - 1] + arr[i]);
	}
	printf("%d\n", temp[num - 1]);
}