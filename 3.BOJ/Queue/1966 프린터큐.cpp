#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {
	int arr[1001] = { 0 };

	int N; //test case ����
	int len; // len : arr/queue�� ����
	int num; //num : ã�� �ε���
	int temp; // ã�� �ε����� ��
	int add1, add2; //add1�� push�� �� �� index�� ���� , add2�� push�� �� �� arr�� ����
	int k, cnt; // k �� arr ��ȸ�� index �� , cnt �� ��� ����� �� (�ʱ�ȭ �ʿ�)
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		queue<pair<int, int>> q;
		cnt = 0;
		k = 0;

		scanf("%d %d", &len, &num);
		for (int j = 0; j < len; j++) {
			scanf("%d", &arr[j]); // ���ҵ��� ������ �迭��
			q.push(pair<int, int>(j, arr[j])); // queue�� �� ����� ������ ���� ����
		}
		temp = arr[num]; // temp ���� ã�� �ε����� �� ���� queue�� ���ϱ� ���Ͽ�

		sort(arr, arr + len, compare); // ���� ū�ͺ��� ã�� ���Ͽ� �������� ����

		while (!q.empty()) {
			if (arr[k] == q.front().second) {
				if (temp == q.front().second) {
					if (num == q.front().first) {
						cnt++;
						printf("%d\n", cnt);
						break;
					}
					else {
						cnt++;
						q.pop();
						k++;
					}
				}
				else {
					cnt++;
					q.pop();
					k++;
				}
			}
			else {
				add1 = q.front().first;
				add2 = q.front().second;
				q.pop();
				q.push(pair<int, int>(add1, add2));
			}
		}
	}
}