#include <stdio.h>

int main(void)
{
	int price, given, won1, won2, won3, won4;
	printf("������ ����:");
	scanf_s("%d", &price);
	printf("�����Լ� ���� ȭ��:");
	scanf_s("%d", &given);
	won1 = (given - price) / 10000;
	won2 = (given - price - won1*10000) / 1000;
	won3 = (given - price - won1*10000 - won2*1000) / 100;
	won4 = (given - price - won1*10000 - won2*1000 - won3*100) / 10;
	printf("������ ������ �ܵ�\n");
	printf("�� ����: %d\n", won1);
	printf("õ ����: %d\n", won2);
	printf("�� ��: %d\n", won3);
	printf("�� ��: %d\n", won4);

	return 0;
}