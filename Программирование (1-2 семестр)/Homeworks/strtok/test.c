//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#define _CRT_SECURE_NO_WARNINGS
//
//char* glas(char* str1, char* str2);
//
//int main(void)
//{
//	char s1[100], s2[100], * stroka;
//	puts("vvedite stroku 1");
//	gets(s1);
//	puts("vvedite stroku 2");
//	gets(s2);
//
//	stroka = glas(s1, s2);
//
//	int q = 3;
//	int p = 4;
//
//	putchar('\n');
//	printf("ITOGOVAYA stroka = %s \n\n\n", stroka);
//
//	return 0;
//}
//
//char* glas(char* str1, char* str2)
//{
//	int i, end;
//	putchar('\n');
//	printf("Per: %s\n", str1);
//	printf("Vtor: %s\n", str2);
//	end = strlen(str1);
//	for (i = 0; i < end; i++)
//		str1[i] = toupper(str1[i]);
//	return str1;
//}



//#include < stdio.h >  // ��� printf
//#include < string.h > // ��� strtok
//int main(void)
//{
//	// ������ �� ������� ��� ������
//	char str[26] = "test1/test2///test3/test4";
//	// ����� ��������, ������� ������ ������� � ������� �������
//	char sep[10] = "/";
//	// ����������, � ������� ����� ���������� ��������� ������ ������
//	// ������ str
//	char* istr;
//
//	printf("�������� ������: %s\n", str);
//	printf("��������� ��������� :\n");
//	// ��������� ������ ����� ������
//	istr = strtok(str, sep);
//
//	// ��������� ����������� ������
//	while (istr != NULL)
//	{
//		// ����� ��������� ���������� �����
//		printf("%s\n", istr);
//		// ��������� ��������� ����� ������
//		istr = strtok(NULL, sep);
//	}
//
//	return 0;
//}