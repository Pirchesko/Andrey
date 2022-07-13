#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void error()
{
	printf("bad input");
	exit(0);
}

//������� ��� ������������� ����� � ������� int
long long numtoint(long long num)
{
	if ((num >= 48) && (num <= 57))
	{
		return (num - 48);
	}
	else if ((num >= 65) && (num <= 70))
	{
		return (num - 55);
	}
	else if ((num >= 97) && (num <= 102))
	{
		return (num - 87);
	}
	else if ((num == 44) || (num == 46))
	{
		num = -1;
		return num;
	}
	else
	{
		error();
	}
	return 0;
}

//������� ��� ������������� ����� � ������� char
long long numtochar(long long num)
{
	if ((num >= 0) && (num <= 9))
	{
		return (num + 48);
	}
	else if ((num >= 10) && (num <= 16))
	{
		return (num + 55);
	}
	else
	{
		error();
	}
	return 0;
}

int main()
{
	//p - ������� ��
	//q - ����� ��
	//ch - ������� �����
	int p, q;
	int input;
	input = scanf("%d %d", &p, &q);
	if (input != 2)
	{
		return 0;
	}
	char ch[14] = { 0 };
	input = scanf("%13s", ch);
	if (input != 1)
	{
		return 0;
	}

	//������������� ����������
	int k;
	int c;
	int lenth = strlen(ch);

	//�������� �� bad input
	if (p < 2 || q < 2 || q > 16 || p > 16) //�� ������ ���� �� 2-������ �� 16-������
	{
		error();
	}
	if ((ch[0] == ',') || (ch[0] == '.') || (ch[lenth - 1] == ',') || (ch[lenth - 1] == '.')) //����� �� ����� ���������� � ������������� ������ ��� �������
	{
		error();
	}
	long long n; //� ����� ����� �� ��������� ��
	c = 0;//��������� ���������� �������
	int tochka = -1; //���������� �����
	int ktochka = 0; //�������� �� ���������� �����
	for (int i = 0; i < lenth; i++)
	{
		n = numtoint(ch[i]);
		if (n == -1)
		{
			tochka = i;
			ktochka += 1;
		}
		if ((n >= p) && (n != -1))
		{
			error();
		}
		c++;
	}
	if (ktochka > 1) //����� �� ����� ���� ������ 2-��
	{
		error();
	}
	if ((ch[0] == '0') && (ch[1] != ',') && (ch[1] != '.') && (c > 1))//����� �� ����� ���������� � 0 (����� ������� � ������� ������)
	{
		error();
	}

	//���� ���������� �����
	int xt = tochka;
	if (tochka == -1)
	{
		xt = lenth;
	}

	//������ ������� �������� ��� �������� � ����� ��
	long long st[13];
	st[0] = 1;
	for (int i = 1; i < 13; i++)
	{
		st[i] = st[i - 1] * p;
	}

	//ch10 - ��������� ����� ����� � 10-������ ��
	long long ch10 = 0;
	k = 0;//����������
	for (int i = xt - 1; i >= 0; i--)//i - �������
	{
		ch10 += numtoint(ch[k]) * st[i];
		k++;
	}

	//ch10t - ��������� ������� ����� � 10-������ ��
	long long ch10t = 0;
	long long qdel = 0; //qdel - �������� ��� �������� ������� ����� � ����� ��
	//int numb;
	if ((tochka != -1) && (xt != lenth))
	{
		qdel = q * st[lenth - xt - 1];
		k = lenth - xt - 2;//�������
		for (int i = xt + 1; i < lenth; i++)//i - ����������
		{
			ch10t += numtoint(ch[i]) * st[k];
			k--;
		}
	}

	//������� ���������� ���� ��� ����� ��
	c = 0;
	long long ch10n = ch10;
	if (ch10n == 0)
	{
		c++;
	}
	while (ch10n > 0)
	{
		c++;
		ch10n /= q;
	}

	//��������� � ����� �� (����� �����)
	char newch[64] = { 0 };
	int c1 = c;//����������
	ch10n = ch10;
	while (c1 > 0)
	{
		n = ch10n % q;
		newch[c1 - 1] = numtochar(n);
		ch10n /= q;
		c1--;
	}

	//��������� � ����� �� (������� �����)
	k = 0;//������������ 12 �������� ����� �������
	int c2 = c;//����������
	if ((tochka != -1) && (ch10t != 0))
	{
		ch10t = (ch10t * q) - (qdel * ((ch10t * q) / qdel)); //������ ������ ����� ������ 0, ������� �� ��� ���������
		while ((ch10t > 0) && (k < 12))
		{
			n = (ch10t * q) / qdel;
			newch[c2 + 1] = numtochar(n);
			c2++;
			k++;
			ch10t = (ch10t * q) - (qdel * n);
		}
	}
	else
	{
		tochka = -1;
	}

	//�������������� ����� ��� ������
	if (tochka != -1)
	{
		k = c2 + 1;
		newch[c] = '.';
	}
	else
	{
		k = c - 1;
	}
	//������� �����
	for (int i = 0; i <= k; i++)
	{
		printf("%c", newch[i]);
	}

	return 0;
}
