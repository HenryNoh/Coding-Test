#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int arr[1001] = { 0 };
	queue<int> q;
	int N, K, temp, j = 0;
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		for (int i = 1; i <= K - 1; i++) {
			temp = q.front();
			q.pop();
			q.push(temp);
		}
		temp = q.front();
		q.pop();
		arr[j] = temp;
		j++;
	}
	printf("<");
	for (int i = 0; i < N - 1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d>", arr[N - 1]);
}