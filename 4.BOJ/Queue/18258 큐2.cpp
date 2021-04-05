#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int* arr;
	arr = (int*)malloc(sizeof(int) * 2000000); // int 배열로는 25만개 까지만 할당가능
	int i, front = 0, back = 0, push, N;
	char str[6];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", str);
		if (strcmp(str, "push") == 0) {
			scanf("%d", &push);
			back++;
			arr[back] = push;
		}
		else if (strcmp(str, "pop") == 0) {
			if (back - front == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", arr[front + 1]);
				arr[front + 1] = 0;
				front++;
			}
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", back - front);
		}
		else if (strcmp(str, "empty") == 0) {
			if (back - front == 0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		else if (strcmp(str, "front") == 0) {
			if (back - front == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", arr[front + 1]);
			}
		}
		else if (strcmp(str, "back") == 0) {
			if (back - front == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", arr[back]);
			}
		}
	}
}