#include <stdio.h>
#include <algorithm>

int main(void) {
	int i = 0, num = 0, sum = 0, cur = 0;
	int arr[1001];
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	std::sort(arr, arr + num);

	for (i = 0; i < num; i++) {
		cur = cur + arr[i];
		sum = sum + cur;
	}
	printf("%d", sum);
}