#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int year = 2019, mon;
	int total = 1;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i;

	printf("�� �Է� : ");
	scanf("%d", &mon);

	for (i = 2018; i < year; i++) {
		total += 365;
	}

	for (i = 0; i < mon - 1; i++) {
		total += month[i];
	}

	printf("\n\t\t\t%d��\n", mon);
	printf("---------------------------------------------------\n");
	printf("��\t��\tȭ\t��\t��\t��\t��\n");
	printf("---------------------------------------------------\n");

	//1����� 2019������� �� �ϼ��� 7�� ������ �������� 0�̸� �Ͽ���, 1�̸� �������� �ǵ��� ����� �Լ�
	int start, end; //1���� �����ϴ� �ڸ�, ������ ���� ������ �ڸ�
	start = total % 7;
	end = month[mon - 1];
	for (i = 0; i < start; i++) {
		printf("\t");
	}
	for (i = 1; i <= end; i++) {
		printf("%2d\t", i);
		if ((i + start) % 7 == 0) {
			printf("\n");
		}
	}


	return 0;
}