#include <stdio.h>

int main(void) {

	int n, i;
	float num;
	float nums[1000]; 
	float max, min; //�ִ밪, �ּҰ��� ���� ����
	float avg = 0; //��հ��� ���� ����
	float sum = 0; //num�� ��


	printf("�Է��� ���� �� ���ΰ�? :");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("���� �Է����ּ��� :");
		scanf("%f", &num);
		nums[i] = num;

	}

	max = nums[0];

	for (i = 0; i < n; i++) {
		if (nums[i] >= max) {
			max = nums[i];
		}
	}

	min = nums[0];

	for (i = 0; i < n; i++) {
		if (nums[i] <= min) {
			min = nums[i];
		}
	}

	for (i = 0; i < n; i++) {
		sum += nums[i];
	}

	avg = sum / n;

	printf("�ִ밪: %.2f\n�ּҰ�: %.2f\n��հ�: %.2f\n", max, min, avg);

}