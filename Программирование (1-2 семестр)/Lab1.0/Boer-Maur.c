////#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable : 4996)
//#include <stdio.h>;
//#include <string.h>
//#include <malloc.h>
//#include <stdlib.h>
//
//int main()
//{
//	//�������������� ����������
//	int input;
//	int k;
//	int check;
//
//	//��������� ������
//	char pattern[17] = { 0 };
//	input = scanf("%16s", pattern);
//	if (input != 1)
//	{
//		return 0;
//	}
//
//	//��������� ������
//	char* string; //������
//	int d_string; //����� ������
//	k = 0;
//	string = (char*)malloc(sizeof(char*));
//	string[k] = getchar();
//	while ((string[k] != '\n') || (k == 0))
//	{
//		k++;
//		string = (char*)realloc(string, k * sizeof(char*));
//		if (string != NULL)
//		{
//			string[k] = getchar();
//		}
//		else
//		{
//			free(string);
//			exit(1);
//		}
//	}
//	if (string[k - 1] == '\n')
//		string[k - 1] = '\0';
//	else
//		string[k] = '\0';
//	d_string = strlen(string);
//
//	//������ ������ �������
//	int d_pattern = strlen(pattern);
//	int sdvig[17] = { 0 }; //������ �������
//	k = 1;
//	check = 0; //���������� ��� �������� ��������� �������� � �������
//	for (int i = d_pattern - 2; i >= 0; i--)
//	{
//		for (int j = d_pattern - 2; j > i; j--)//���� ��� ������ ��������� ��������
//		{
//			if (pattern[j] == pattern[i])
//			{
//				sdvig[i] = sdvig[j];
//				check = 1;
//				break;
//			}
//		}
//		if (check == 0)
//		{
//			sdvig[i] = k;
//		}
//		else
//		{
//			check = 0;
//		}
//		k++;
//	}
//	check = 0; //���������� ��� �������� ��������� �������� � �������
//	for (int i = d_pattern - 2; i >= 0; i--)//��������� ���������� �������� ������ ��������
//	{
//		if (pattern[d_pattern - 1] == pattern[i])//����� ���� �������
//		{
//			check = 1;
//			sdvig[d_pattern - 1] = sdvig[i];
//			break;
//		}
//	}
//	if (check == 0)
//	{
//		sdvig[d_pattern - 1] = k;
//	}
//	sdvig[d_pattern] = k;//�������� ���� �� ������� �� ���� ������ �������
//
//	//���� ���������
//	int p_string = d_pattern; //������� ������
//	int p_pattern = d_pattern - 1; //������� �������
//	//char c[1] = { 0 };
//	k = 0;
//	while (p_string < d_string)
//	{
//		if (pattern[p_pattern] == string[p_string])
//		{
//			k++;
//			printf("%d", p_string);
//			p_pattern--;
//			p_string--;
//		}
//		else if ((pattern[p_pattern] != string[p_string]) && (k == 0))
//		{
//			p_pattern = d_pattern - 1;
//			//c[0] = string[p_string];
//			//p_string +=
//		}
//		else if ((pattern[p_pattern + 1] != string[p_string]) && (k != 0))
//		{
//
//		}
//	}
//
//	printf("%c", string[1]);
//
//	/*
//	//����� �������
//	for (int i = 0; i <= d_pattern; i++)
//	{
//		printf("%d ", sdvig[i]);
//	}
//	*/
//	return 0;
//}
