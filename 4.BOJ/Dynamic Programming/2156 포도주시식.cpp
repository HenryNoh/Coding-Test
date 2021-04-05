#include <stdio.h>
int compare(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {
    int num, i;
    int DP[10001] = { 0 }, temp[10001] = { 0 };

    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
        scanf("%d", &DP[i]);
    }

    temp[1] = DP[1];
    temp[2] = DP[1] + DP[2];

    for (i = 3; i <= num; i++) {
        temp[i] = compare(temp[i - 3] + DP[i - 1] + DP[i], temp[i - 2] + DP[i]);
        temp[i] = compare(temp[i - 1], temp[i]);
    }

    printf("%d", temp[num]);
}