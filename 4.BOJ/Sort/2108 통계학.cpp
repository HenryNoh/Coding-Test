#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Limit 8001

int main(void) {
int i, j=0, k = 0, n, num, mid, mode=0, size; //mid: �߰��� size: ����
int sum = 0, max_num = 0; // max_num: mode���� �ִ밪 ���ϴ� ����

scanf("%d", &num);
int *arr = (int*)malloc(sizeof(int)*num);
int count[Limit] = { 0 };
int max[Limit] = { 0 };

for (i = 0; i<num; i++) {
	scanf("%d", &n);
	sum = sum + n;
	max[n + 4000]++; //�ֺ� ���ϱ� ���Ͽ� �� �Է¹��� ���� �ش�ĭ�� ++ �����ֱ� (ī��������)
}
double avg = round(sum / (double)num); // �ݿø��� ���ؼ� num�� double�� ����ȯ

for (i = 0; i<Limit; i++) {
	if (max[i]>max_num) { //max �迭�� ���� max_num���� Ŭ ��� 
		j = 0; //count �迭�� �ʱ�ȭ ��
		max_num = max[i]; // max_num�� ���ο� ������ ����
		count[j] = i - 4000; //count[0]�� �ε���-4000�� ������ ����
		j++;
	}
	else if (max[i] == max_num) { //max �迭�� ���� max_num�� ���� ���
		count[j] = i - 4000; //count[j]�� �ε���-4000�� ������ ����
		j++;
	}
	if (max[i]>0) { //max �迭�� �� ����ִ� ���
		while (max[i]>0) { 
			arr[k++] = i - 4000; //arr�� �Է°� ���� (���� ������ ���ʴ�� ����ǹǷ� mid�� ���)
			max[i]--; // max �迭�� ���
		}
	}
}
if (j == 1) { //j==1�� ���� �ֺ��� 1���� ���
	mode = count[0];
}
else if (j>1) { //j==1�� ���� �ֺ��� 2���̻��� ���
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
