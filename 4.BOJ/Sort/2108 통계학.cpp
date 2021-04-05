#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Limit 8001

int main(void) {
int i, j=0, k = 0, n, num, mid, mode=0, size; //mid: 중간값 size: 범위
int sum = 0, max_num = 0; // max_num: mode값의 최대값 구하는 변수

scanf("%d", &num);
int *arr = (int*)malloc(sizeof(int)*num);
int count[Limit] = { 0 };
int max[Limit] = { 0 };

for (i = 0; i<num; i++) {
	scanf("%d", &n);
	sum = sum + n;
	max[n + 4000]++; //최빈값 구하기 위하여 각 입력받은 수의 해당칸에 ++ 시켜주기 (카운팅정렬)
}
double avg = round(sum / (double)num); // 반올림을 위해서 num을 double로 형변환

for (i = 0; i<Limit; i++) {
	if (max[i]>max_num) { //max 배열의 값이 max_num보다 클 경우 
		j = 0; //count 배열을 초기화 후
		max_num = max[i]; // max_num은 새로운 값으로 변경
		count[j] = i - 4000; //count[0]은 인덱스-4000의 값으로 저장
		j++;
	}
	else if (max[i] == max_num) { //max 배열의 값이 max_num과 같을 경우
		count[j] = i - 4000; //count[j]에 인덱스-4000의 값으로 저장
		j++;
	}
	if (max[i]>0) { //max 배열이 안 비어있는 경우
		while (max[i]>0) { 
			arr[k++] = i - 4000; //arr에 입력값 저장 (낮은 수부터 차례대로 저장되므로 mid에 사용)
			max[i]--; // max 배열을 비움
		}
	}
}
if (j == 1) { //j==1인 경우는 최빈값이 1개인 경우
	mode = count[0];
}
else if (j>1) { //j==1인 경우는 최빈값이 2개이상인 경우
	mode = count[1];
}
mid = arr[(num - 1) / 2];
size = arr[num - 1] - arr[0];

printf("%.f\\n", avg);
printf("%d\\n", mid);
printf("%d\\n", mode);
printf("%d", size);
free(arr);
}
