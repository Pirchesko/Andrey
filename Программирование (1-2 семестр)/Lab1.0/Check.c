//#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable : 6387)
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//�������� �������
void Create_stop_symbols(int* stop_symbols, char* pattern) {
    int d_pattern = strlen(pattern) - 1;
    int k = 1;
    //��������� ������ � �������������� ��������
    for (int i = d_pattern - 2; i >= 0; i--)
    {
        if (stop_symbols[(int)pattern[i]] == 0)
        {
            stop_symbols[(int)pattern[i]] = k;
        }
        k++;
    }
    //��������� ��������� ������� �������
    if (stop_symbols[(int)pattern[d_pattern - 1]] == 0)
    {
        stop_symbols[(int)pattern[d_pattern - 1]] = k;
    }
    //��������� ���������� �����
    for (int i = 0; i < 256; i++)
    {
        if (stop_symbols[i] == 0)
        {
            stop_symbols[i] = d_pattern;
        }
    }
}

//����� ��������� � ������
void Algoritm_Boyer_Moore(char* text, char* pattern, int* stop_symbols) {
    int d_text = strlen(text); //����� ������
    int d_pattern = strlen(pattern) - 1; //����� �������
    int k_pattern = d_pattern - 1; //��������� ����� ������� (���������� �������)
    while (k_pattern < d_text) //������ �� ������ ����� �� ������� ������
    {
        int k1_pattern = d_pattern - 1; //���������� ������� �� ������ ����� �����
        int k_text = k_pattern; //���������� ������
        while ((k1_pattern > 0) && (pattern[k1_pattern] == text[k_text])) //����������
        {
            printf("%d ", k_text + 1); //������� �� 1 ������ �.�. ��� �������, � �� ������
            k_text--;
            k1_pattern--;
        }
        printf("%d ", k_text + 1); //������� �� 1 ������ �.�. ��� �������, � �� ������
        k_pattern += stop_symbols[(int)text[k_pattern]]; //�������� ������
    }
}

int main()
{
    int stop_symbols[256] = { 0 }; //������ ���� ��������

    //���������� �������
    char pattern[20] = { 0 }; //������
    if (fgets(pattern, 20, stdin) == NULL)
    {
        return 0;
    } 

    //���������� ������
    char text[100] = { 0 }; //�����
    int i = 0;
    text[i] = getchar();
    while (text[i] != EOF)
    {
        i++;
        text[i] = getchar();
    }
    text[i] = '\0';
    
    //������ ���������
    Create_stop_symbols(stop_symbols, pattern); //������ ������� ����-��������
    Algoritm_Boyer_Moore(text, pattern, stop_symbols); //��������� �������� ����-����
    return 0;
}
