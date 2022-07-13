#include <stdio.h>
#include <string.h>

int i = 0; //�������
int d_str = -1; //����� ������
int d_sep = -1; //����� �������
int j = 0; //������ ����� ����� str

void check_double_sep(char* str, char* sep)
{
	//��� ������� ��� ����, ����� ��� ������� ������ ������ "�������" ��� ������ �� ����
	for (int k = 0; k < d_sep; k++)
	{
		if (str[i] == sep[k])
		{
			i++;
			check_double_sep(str, sep);
		}
	}
}

char* mystrtok(char* str, char* sep)
{
	if ((d_str == -1) || (d_sep == -1))	//�������� �����
	{
		d_str = strlen(str);
		d_sep = strlen(sep);
	}
	check_double_sep(str, sep); //������� ���������� �� ������� ������
	j = i; //������ ��� ����� �����
	int i1 = 99999; //�.�. �������� ����� �� ���������� ������ ���������� i ����� ���� ������, ����� ����������� �
	for (int k = 0; k < d_sep; k++)
	{
		while (str[i] != sep[k]) //���� ���������� � ������� ���������� ��������� �������
		{
			if (i >= d_str) //���������� �� ������ ����� �� ������� ������
			{
				break;
			}
			i++;
		}
		if (i < i1) //���� ����������� i
		{
			i1 = i;
		}
		i = j; //�.�. �������� ������ ��������� ���, ��������� ����������� �������� i
	}
	i = i1;
	if (i <= d_str) //������������ ������ �� �������
	{
		str[i] = '\0';
		i++;
	}
	else //���� ��� ����� ������
	{
		return NULL;
	}
	return (str + j); //������ +j ����� ����� ��������� � ������ �������
}

int main(void)
{
	// ������ �� ������� ��� ������
	char str[100];
	// ����� ��������, ������� ������ ������� � ������� �������
	char sep[100];
	// ����������, � ������� ����� ���������� ��������� ������ ������
	char* istr;

	puts("Stroka: ");
	gets(str);
	puts("Lexema: ");
	gets(sep);

	istr = mystrtok(str, sep);
	while (istr != NULL)
	{
		printf("%s\n", istr);
		istr = mystrtok(str, sep);
	}
	return 0;
}