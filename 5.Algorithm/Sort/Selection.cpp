#include <stdio.h>

int main(int argc, char* argv[]) {
	int i, j, min, idx, temp;
	int array[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 10; i++) {
		min = 9999;
		for (j = i; j < 10; j++) {
			if (min > array[j]) {
				min = array[j];
				idx = j;
			}
		}
		temp = array[i];
		array[i] = array[idx];
		array[idx] = temp;
	}
	for (i = 0; i < 10; i++) {
		printf("%d", array[i]);
	}
	return 0;
}