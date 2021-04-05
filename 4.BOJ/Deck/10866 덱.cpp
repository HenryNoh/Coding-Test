#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int Deque[10001] = { 0, };
	int i, num, temp = 0;
	int front = 5000;
	int back = 5001;
	char str[15];
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%s", str);

		if (strcmp(str, "push_front") == 0) {
			scanf("%d", &temp);
			Deque[front] = temp;
			front--;
		}
		else if (strcmp(str, "push_back") == 0) {
			scanf("%d", &temp);
			Deque[back] = temp;
			back++;
		}
		else if (strcmp(str, "pop_front") == 0) {
			if (back - front <= 1) {
				printf("-1\n");
			}
			else {
				printf("%d\n", Deque[front + 1]);
				front++;
			}
		}
		else if (strcmp(str, "pop_back") == 0) {
			if (back - front <= 1) {
				printf("-1\n");
			}
			else {
				printf("%d\n", Deque[back - 1]);
				back--;
			}
		}
		else if (strcmp(str, "size") == 0) {
			printf("%d\n", back - front - 1);
		}
		else if (strcmp(str, "empty") == 0) {
			((back - front - 1) == 0) ? printf("1\n") : printf("0\n");
		}
		else if (strcmp(str, "front") == 0) {
			if (back - front <= 1) {
				printf("-1\n");
			}
			else {
				printf("%d\n", Deque[front + 1]);
			}
		}
		else if (strcmp(str, "back") == 0) {
			if (back - front <= 1) {
				printf("-1\n");
			}
			else {
				printf("%d\n", Deque[back - 1]);
			}
		}
	}
}