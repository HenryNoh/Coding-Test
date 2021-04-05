#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <deque>

using namespace std;

int main(void) {
	int T, n;
	char p[100001];
	char str[400001];
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		deque<int> dq;
		int R_cnt = 0;
		int D_cnt = 0;
		int temp = 0;
		scanf("%s", p);
		scanf("%d", &n);
		scanf("%s", str);
		int str_len = strlen(str);
		int p_len = strlen(p);
		for (int i = 0; i < str_len; i++) {
			if (str[i] >= 48 && str[i] <= 57) {
				temp = temp * 10 + str[i] - 48;
			}
			else {
				if (temp != 0) {
					dq.push_back(temp);
				}
				temp = 0;
			}
		}
		for (int i = 0; i < p_len; i++) {
			if (p[i] == 'R') {
				R_cnt++; // R이 먼저 들어올 경우 R에 대한 카운트 추가
			}
			if (p[i] == 'D') { // D가 들어올 경우
				D_cnt++;
				if (dq.size() < 1) {
					printf("error\n");
					break;
				}
				if (R_cnt % 2 == 1) { // R 카운트가 홀수일 경우
					dq.pop_back();
				}
				else if (R_cnt % 2 == 0) { // R 카운트가 짝수일 경우
					dq.pop_front();
				}
			}
		}
		int size = dq.size();
		if (D_cnt <= n) {
			if (R_cnt % 2 == 0) {
				printf("[");
				for (int i = 0; i < size; i++) {
					printf("%d", dq.front());
					if (i < size - 1) {
						printf(",");
					}
					dq.pop_front();
				}
				printf("]\n");
			}
			else {
				printf("[");
				for (int i = 0; i < size; i++) {
					printf("%d", dq.back());
					if (i < size - 1) {
						printf(",");
					}
					dq.pop_back();
				}
				printf("]\n");
			}
		}
		else {
			continue;
		}
	}
}