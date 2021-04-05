#include <iostream>
#include <string.h>
#include <stack>

int main(void) {
	stack<int> s1; // 입력 배열 넣을 스택
	stack<int> s2; // 비교할 스택
	int i, j = 0, num = 0, temp = 0, check = 0;
	int arr[100001]; // 입력받은 배열
	char result[100001];
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = num; i > 0; i--) {
		s1.push(arr[i]);
	}
	i = 0;
	while (!s1.empty()) {
		if (s1.top() > i) {
			i++;
			s2.push(i);
			result[j] = '+';
			j++;
		}
		else if (s1.top() < s2.top()) {
			check = 1;
			break;
		}
		else if (!s2.empty() && s1.top() == s2.top()) {
			s1.pop();
			s2.pop();
			result[j] = '-';
			j++;
		}
	}
	if (check == 1) {
		printf("NO");
	}
	else {
		for (int k = 0; k < j; k++) {
			printf("%c\n", result[k]);
		}
	}
}