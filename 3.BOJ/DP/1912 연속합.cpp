#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS

int compare(int a, int b) {
	return (a > b) ? a : b;
}

int main(void) {
	int num, i, max = -1000, sum = 0;
	int arr[100001] = { 0 };

	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > 0) { //해당 값이 양수일 경우
			if (sum < 0) { //이전 값까지의 합이 음수일 경우
				sum = 0; //더해온 값을 초기화하고
				sum = sum + arr[i]; //새로 저장한다.
			}
			else { //이전 값까지의 합이 양수일 경우
				sum = sum + arr[i]; //계속 더해준다.
			}
			max = compare(max, sum); //if(sum<0)일 경우 새로 더한값이 클수 있기에 비교해준다.
		}
		else { //해당 값이 음수일 경우
			if (sum <= 0) { //이전 값까지의 합이 음수일 경우
				max = compare(max, arr[i]); //더할 필요 없이 비교해준다.
			}
			else { //이전 값까지의 합이 양수일 경우
				sum = sum + arr[i]; //다음 수들로 합이 더 커질수 있으므로 합산만 해준다.
			}
		}
	}
	printf("%d", max);
}