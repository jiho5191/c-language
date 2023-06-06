#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

void period(void);                                        //���� �Ⱓ �Լ�
void parking(void);                                      //�ܱ�,��� ���� ���� �Լ�
void car(void);                                          //���� ���� �Լ�
void reduction(void);                                    //��ݰ��� ���� �Լ�
void parking_fee(void);                                   //���� ��� ��� �Լ�
int parking_period;                                      //�ܱ�, ��� ������ ������ ����
int num;                                                 //����, ������ ������ ����
int reduct;                                              //��ݰ����� ������ ����
int tm_day, tm_hour, tm_min;                             // �ð� ���� ������ ����

int main() {
	printf("���� ��� ����\n\n");
	period();
	parking();
	if (parking_period == 2) { //�ܱ����� ������ �¿��� �ۿ� ���� ������ ���� �ʰ� �Ѿ��.
		printf("\n�¿���, 15�� ���� ����, �ִ����緮 1�� ���� ȭ������ ���� �������� ���е˴ϴ�.\n");
		car();
	}
	else {
		num = 1;
	}
	reduction();
	parking_fee();

	return 0;
}

void parking(void) {
	printf("\n1�� �̻� ������� ������ ����������� �̿��Ͽ� �ֽñ� �ٶ��ϴ�.\n");
	printf("1.�ܱ�����(�¿��� ����)   2.�������  : ");
	scanf("%d", &parking_period);
	if ((parking_period != 1) && (parking_period != 2)) {
		printf("�ٽ� �Է����ּ���\n");
		parking();
	}
}

void car(void) {
	printf("1.����   2.����  : ");
	scanf("%d", &num);
	if ((num != 1) && (num != 2)) {
		printf("�ٽ� �Է����ּ���\n");
		car();
	}
}

void period(void) {
	time_t start, end;
	double diff;

	// time1 �Է�
	struct tm user_stime;
	int fy, fm, fd, fh, fmin;

	// time1�� �Է�
	printf("���� ��¥�� �Է����ּ��� (��:yyyy mm dd) : ");
	scanf_s("%d %d %d", &fy, &fm, &fd);
	printf("���� �ð��� �Է����ּ��� (��:hh mm) : ");
	scanf_s("%d %d", &fh, &fmin);


	// time1 ����ü�� ����
	user_stime.tm_year = fy - 1900; // �⵵�� 1900����� �����ϱ� ����
	user_stime.tm_mon = fm - 1; //���� 0���� �����ϱ� ����
	user_stime.tm_mday = fd;
	user_stime.tm_hour = fh;
	user_stime.tm_min = fmin;
	user_stime.tm_isdst = 0; //���Ÿ�� ������

	// time2 �Է�
	struct tm user;
	int sy, sm, sd, sh, smin;

	// time2�� �Է�
	printf("���� ��¥�� �Է����ּ��� (��:yyyy mm dd) :  ");
	scanf_s("%d %d %d", &sy, &sm, &sd);
	printf("���� �ð��� �Է����ּ��� (��:hh mm) : ");
	scanf_s("%d %d", &sh, &smin);

	// time2 ����ü�� ����
	user.tm_year = sy - 1900; // �⵵�� 1900����� �����ϱ� ����
	user.tm_mon = sm - 1; //���� 0���� �����ϱ� ����
	user.tm_mday = sd;
	user.tm_hour = sh;
	user.tm_min = smin;
	user.tm_isdst = 0; //���Ÿ�� ������

	start = mktime(&user_stime);
	end = mktime(&user);

	// �ð� ���� ���
	diff = difftime(end, start);

	// �� ���
	tm_day = diff / (60 * 60 * 24);
	diff = diff - (tm_day * 60 * 60 * 24);

	// �ð� ���
	tm_hour = diff / (60 * 60);
	diff = diff - (tm_hour * 60 * 60);

	// �� ���
	tm_min = diff / 60;
	diff = diff - (tm_min * 60);
}

void reduction(void) {
	printf("\n1.�ش���� ����   2.����/�����/����������/���ڳడ��/�������ڵ��� 1��,2��   3.�������ڵ��� 3��  : ");
	scanf("%d", &reduct);
	if ((reduct != 1) && (reduct != 2) && (reduct != 3)) {
		printf("�ٽ� �Է����ּ���\n");
		reduction();
	}
}

void parking_fee(void) {
	int fee = 0; //�� ��� ���

	//�ܱ������� ��, ������� ���
	if (parking_period == 1) {
		fee = 1200;     //�⺻ 30�� ��� 1200��

		for (int n = 0; n < tm_day; n++) {
			fee += 24000;     //�Ϸ� �ִ� ��������� 24000���̴�.
		}

		if (tm_hour <= 10) {
			for (int n = 0; n < tm_hour; n++) {
				fee += 2400;
			}

			if (tm_min == 0) fee;
			else if (tm_min <= 15) {
				fee += 600;
			}
			else if (tm_min <= 30) {
				fee += 1200;
			}
			else if (tm_min <= 45) {
				fee += 1800;
			}
			else if (tm_min <= 60) {
				fee += 2400;
			}
		}
		else fee += 24000;

		if ((tm_hour != 0) || (tm_day != 0)) {
			fee = fee - 1200; //�Ϸ� 30�� �⺻ ���
		}
	}

	//��������� ��, ������� ���
	else if (parking_period == 2) {
		//���� ����
		if (num == 1) {
			for (int n = 0; n < tm_day; n++) {
				fee += 9000;     //�Ϸ� �ִ� ��������� 9000���̴�.
			}

			if (tm_hour <= 9) {
				for (int n = 0; n < tm_hour; n++) {     //�ð��� 1000��
					fee += 1000;
				}

				if (tm_min == 0) fee;
				else if (tm_min <= 60) {
					fee += 1000;
				}
			}
			else fee += 9000;
		}
		//���� ����
		else if (num == 2) {
			for (int n = 0; n < tm_day; n++) {
				fee += 12000;     //�Ϸ� �ִ� ��������� 12000���̴�.
			}

			if (tm_hour <= 5) {
				for (int n = 0; n < tm_hour; n++) {
					fee += 2400;
				}

				if (tm_min == 0) fee;
				else if (tm_min <= 30) {
					fee += 1200;
				}
				else if (tm_min <= 60) {     //30�д� 1200��
					fee += 2400;
				}
			}
			else fee += 12000;
		}
	}

	//���������� ������ ������� ���
	if (reduct == 1) {
		printf("\n���� ��������� %d�� �Դϴ�.\n", fee);
	}
	else if (reduct == 2) {
		fee = fee / 2;     //50% ����
		printf("\n���� ��������� %d�� �Դϴ�.\n", fee);
	}
	else if (reduct == 3) {
		fee = fee * 8 / 10;     //20% ����
		printf("\n���� ��������� %d�� �Դϴ�.\n", fee);
	}
}