#include <stdio.h>

int main(void) {
	int i = 0, num = 0;
	scanf("%d", &num);
	int *arr = (int*)calloc(10, sizeof(int));

	while (num != 0) {//입력 받은 값이 0이 아닐때까지
		arr[num % 10]++; //입력 받은 값 10으로 나눈 나머지 인덱스에 arr++
		num = num / 10; //저장 후 10으로 나누기

	}

	for (i = 9; i >= 0; i--) {
		while (arr[i] > 0) {
			printf("%d", i);
			arr[i]--;
		}
	}
}