#include <stdio.h>
#include <algorithm>

struct arr {
	int x;
	int y;
};

arr array[100000];

bool compare(arr const &a, arr const &b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int main(void) {
	int i = 0, num = 0, x, y;
	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &x);
		scanf("%d", &y);
		array[i] = { x,y };
	}

	std::sort(array, array + num, compare);

	for (i = 0; i < num; i++) {
		printf("%d %d\n", array[i].x, array[i].y);
	}
}