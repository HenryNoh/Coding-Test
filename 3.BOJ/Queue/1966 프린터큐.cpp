#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void) {
	int arr[1001] = { 0 };

	int N; //test case 갯수
	int len; // len : arr/queue의 길이
	int num; //num : 찾을 인덱스
	int temp; // 찾을 인덱스의 값
	int add1, add2; //add1은 push할 때 쓸 index값 저장 , add2는 push할 때 쓸 arr값 저장
	int k, cnt; // k 는 arr 순회할 index 값 , cnt 는 결과 출력할 값 (초기화 필요)
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		queue<pair<int, int>> q;
		cnt = 0;
		k = 0;

		scanf("%d %d", &len, &num);
		for (int j = 0; j < len; j++) {
			scanf("%d", &arr[j]); // 원소들을 정렬할 배열과
			q.push(pair<int, int>(j, arr[j])); // queue에 각 페어의 순서와 값을 저장
		}
		temp = arr[num]; // temp 값에 찾을 인덱스의 값 저장 queue와 비교하기 위하여

		sort(arr, arr + len, compare); // 값이 큰것부터 찾기 위하여 내림차순 정렬

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