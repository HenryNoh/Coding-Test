#include <iostream>
#include <stdlib.h>
#include <deque>

using namespace std;

int main(void) {
	int len, n, num, temp, index = 1, cnt = 0, result = 0;
	scanf("%d %d", &len, &n);
	deque<int> dq;

	for (int i = 1; i <= len; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		for (int i = 0; i < dq.size(); i++) {
			if (num == dq[i]) {
				index = i + 1;
				break;
			}
		}
		if (index - 1 < dq.size() - index + 1) {
			cnt = index - 1;
			result = result + cnt;
			for (int i = 0; i < cnt; i++) {
				temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
			}
			dq.pop_front();
		}
		else {
			cnt = dq.size() - index + 1;
			result = result + cnt;
			for (int i = 0; i < cnt; i++) {
				temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
			}
			dq.pop_front();
		}
	}
	printf("%d", result);
}