#include <stdio.h>

int white = 0;
int blue = 0;
int arr[129][129] = { 0 };

void divide(int xs, int ys, int xe, int ye) {
	int check = arr[xs][ys];
	for (int i = xs; i <= xe; i++) {
		for (int j = ys; j <= ye; j++) {
			if (check == 0 && arr[i][j] == 1) {
				check = 2;
			}
			else if (check == 1 && arr[i][j] == 0) {
				check = 2;
			}
			if (check == 2) {
				divide(xs, ys, (xs + xe) / 2, (ys + ye) / 2);
				divide(((xs + xe) / 2) + 1, ys, xe, (ys + ye) / 2);
				divide(xs, ((ys + ye) / 2) + 1, (xs + xe) / 2, ye);
				divide(((xs + xe) / 2) + 1, ((ys + ye) / 2) + 1, xe, ye);
				return;
			}
		}
	}
	if (check == 0) {
		white++;
	}
	if (check == 1) {
		blue++;
	}
}

int main(void) {
	int num;

	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	divide(1, 1, num, num);
	printf("%d\n%d", white, blue);
}
