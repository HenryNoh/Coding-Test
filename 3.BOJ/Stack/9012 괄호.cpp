#include <stdio.h>
#include <string.h>

int main(void) {
	int N, i, j = 0, num, sum = 0, cnt = 0;
	char str[51];
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		cnt = 0;
		scanf("%s", str);
		int len = strlen(str);
		for (j = 0; j < len; j++) {
			if (cnt < 0) {
				break;
			}
			if (str[j] == '(') {
				cnt++;
			}
			else if (str[j] == ')') {
				cnt--;
			}
		}
		if (cnt == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}