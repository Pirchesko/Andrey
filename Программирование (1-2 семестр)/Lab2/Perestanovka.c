//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//������
void error()
{
	printf("bad input");
	exit(0);
}

//�������� �� ������������ ����� �������
void check_input(const char* ch, int d, int p)
{
	//�������� �� ���������� �������
	for (int i = 0; i < d; i++)
	{
		if ((ch[i] < '0') || (ch[i] > '9'))
		{
			error();
		}
	}
	//�� ����� ���� ������ �������
	if (p < 1)
	{
		exit(0);
	}
	//������� �� ������ �����������
	for (int i = 0; i < d - 1; i++)
	{
		for (int j = i + 1; j < d; j++)
		{
			if (ch[i] == ch[j])
			{
				error();
			}
		}
	}
}

//����������� ������ � ������ int
void char_to_int(const char* ch, int* a, int d)
{
	for (int i = 0; i < d; i++)
	{
		a[i] = (int)ch[i] - 48;
	}
}

//�������� �������� �� ���-�� ������� � ��������
void check_massive(const int* a, int d)
{
	int check = 0;
	for (int i = d - 2; i >= 0; i--)
	{
		if (a[i] < a[i + 1])
		{
			check = 1;
			break;
		}
	}
	if (check == 0)
	{
		exit(0);
	}
}

//����� ����������� j ������, ��� a[j] < a[j + 1]
int find_J(const int* a, int d)
{
	for (int i = d - 1; i > 0; i--)
	{
		if (a[i] < a[i + 1])
		{
			return i;
		}
	}
	return 0;
}

//����� ����������� l, ������ ��� l > j, ��� �������� a[l] > a[j]
int find_L(const int* a, int d, int j)
{
	for (int i = d - 1; i > 0; i--)
	{
		if ((i > j) && (a[i] > a[j]))
		{
			return i;
		}
	}
	return 0;
}

//������ ������� a[j] � a[l]
void swap(int* a, int j, int l)
{
	int t = a[j];
	a[j] = a[l];
	a[l] = t;
}

//���������� � �������� ������� a[j+1]..a[n]
void obratno(int* a, int j, int d)
{
	int j1 = j + 1;
	//��� ��� �� ����� � ����� ���������� ���������� ������ ������� ������ ���
	int c = (d - j1) / 2;
	int k = 1;
	for (int i = j1; c > 0; i++)
	{
		int t;
		t = a[i];
		a[i] = a[d - k];
		a[d - k] = t;
		c--;
		k++;
	}
}

//������� �����
void print(int* a, int d)
{
	for (int i = 0; i < d; i++)
	{
		printf("%d", a[i]);
	}
}

int main()
{
	//����������
	char ch[11] = { 0 }; //������ ���������� �����
	int d; //������ ������
	int p; //���������� ������������
	int a[11] = { 0 }; //������ ��� �������������� ������ � ������

	//��������� ������
	if (scanf("%10s", ch) != 1) //������ ��� ������������
	{
		return 0;
	}
	if (scanf("%d", &p) != 1) //����� P
	{
		return 0;
	}

	d = strlen(ch); //������ ������
	check_input(ch, d, p); //��������� ������������ �������
	char_to_int(ch, a, d); //����������� ������ � ������ int

	while (p > 0)
	{
		check_massive(a, d); //��������� ����������� ���-�� ������ � ��������
		int j = find_J(a, d); //���� ���������� j, ����� ��� a[j] < a[j + 1]
		int l = find_L(a, d, j); //���� ���������� l, ����� ��� l > j, ��� �������� a[l] > a[j]
		swap(a, j, l); //������ ������� a[j] � a[l]
		obratno(a, j, d); //���������� � �������� ������� a[j + 1]..a[n]
		print(a, d); //������� ����� (���� �����)
		printf("\n");
		p--;
	}
	return 0;
}
