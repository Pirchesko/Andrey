#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

//��������� �����
typedef struct list {
    int value; //�������� �������
    int razrad; //����� �������
    struct list* next;
    struct list* prev;
}list;

//���������� �� bad input
void check_error(int N, char* a, char* b)
{
    if (strlen(a) < strlen(b))
    {
        printf("����������� ������ �����������!");
        exit(0);
    }
    if ((N < 2) || (N > 16))
    {
        printf("������� ������� ������� ���������!");
        exit(0);
    }
}

//��� 16-������
int perevod_tuda(char chislo)
{
    if ((chislo >= '0') && (chislo <= '9'))
    {
        return chislo - '0';
    }
    else if ((chislo >= 'a') && (chislo <= 'f'))
    {
        return chislo - 'a' + 10;
    }
    else if ((chislo >= 'A') && (chislo <= 'F'))
    {
        return chislo - 'A' + 10;
    }
    else
    {
        printf("�������� ������� ���������!");
        exit(0);
    }
}

//������ ��������� �����
void create_chislo(list** chislo, char* numbers, int k)
{
    if (numbers != NULL)
    {
        k = strlen(numbers);
    }
    for (int i = -1; i <= k; i++)
    {
        list* count = (list*)malloc(sizeof(list));
        if ((i == k) || (i == -1))
        {
            count->value = -99;
            count->razrad = -99;
        }
        else
        {
            if (numbers != NULL)
            {
                
                count->value = perevod_tuda(numbers[i]);
            }
            else
            {
                count->value = 0;
            }
            count->razrad = k - i;
        }
        count->prev = (*chislo);
        if ((*chislo) != NULL)
        {
            (*chislo)->next = count;
        }
        (*chislo) = count;
    }
    (*chislo)->next = NULL;
    (*chislo) = (*chislo)->prev;
}

//��� ���������� ���������� �������
void operation_minus_in_razrad(list** umenshaemoe, int N)
{
    //������� ������������ �� ������ ������ ���� ����� "�����"
    int k = 0;
    while (((*umenshaemoe)->prev)->value == 0)
    {
        (*umenshaemoe) = (*umenshaemoe)->prev;
        k++;
    }
    (*umenshaemoe) = (*umenshaemoe)->prev;
    //��������� �� 1 �������
    (*umenshaemoe)->value = (*umenshaemoe)->value - 1;
    //����������� �������
    while (((*umenshaemoe)->next->value == 0) && (k > 0))
    {
        (*umenshaemoe) = (*umenshaemoe)->next;
        (*umenshaemoe)->value = N - 1;
        k--;
    }
    (*umenshaemoe) = (*umenshaemoe)->next;
    //��������� � �������� ����������� �����
    (*umenshaemoe)->value = (*umenshaemoe)->value + N;
}

void raznost_chisel(list* umenshaemoe, list* vichitaemoe, list** raznost, int N)
{
    //�������� ���������
    while (vichitaemoe->razrad != -99)
    {
        if ((umenshaemoe->value - vichitaemoe->value) < 0)
        {
            operation_minus_in_razrad(&umenshaemoe, N);
        }
        (*raznost)->value = umenshaemoe->value - vichitaemoe->value;
        (*raznost) = (*raznost)->prev;
        umenshaemoe = umenshaemoe->prev;
        vichitaemoe = vichitaemoe->prev;
    }
    //���������� �������
    while (umenshaemoe->razrad != -99)
    {
        (*raznost)->value = umenshaemoe->value;
        (*raznost) = (*raznost)->prev;
        umenshaemoe = umenshaemoe->prev;
    }
    //������� ���������
    (*raznost) = (*raznost)->next;
    umenshaemoe = umenshaemoe->next;
    vichitaemoe = vichitaemoe->next;
}

//������� �����
void print_rezult(list* chislo)
{
    //��������� � ������
    while ((chislo)->prev->razrad != -99)
    {
        (chislo) = (chislo)->prev;
    }
    //��������� ������ ������ ������� ���� � ������
    while ((chislo)->value == 0)
    {
        (chislo) = (chislo)->next;
    }
    //������� �����
    while ((chislo)->razrad != -99)
    {
        switch ((chislo)->value)
        {
        case 10: printf("A"); break;
        case 11: printf("B"); break;
        case 12: printf("C"); break;
        case 13: printf("D"); break;
        case 14: printf("E"); break;
        case 15: printf("F"); break;
        default:  printf("%d", (chislo)->value); break;
        }
        chislo = (chislo)->next;
    }
    printf("\n");
}

int main()
{
    //������������ ���������
    system("chcp 1251");
    system("cls");
    
    char input_a[100]; //����������� (����������� ������ ������ �����������)
    char input_b[100]; //����������
    int N; //������� ���������
    int dlina; //���������� ��������

    printf("C������ ��������� (2 - 10): ");
    scanf("%d", &N);
    printf("�����������: ");
    scanf("%s", &input_a);
    printf("����������: ");
    scanf("%s", &input_b);

    check_error(N, input_a, input_b);
    dlina = strlen(input_a);
    list* a = NULL; //�����������
    create_chislo(&a, input_a, dlina);
    list* b = NULL; //����������
    create_chislo(&b, input_b, dlina);
    list* c = NULL; //��������
    create_chislo(&c, NULL, dlina);

    raznost_chisel(a, b, &c, N);
    printf("��������: ");
    print_rezult(c);

    return 0;
}

//������
//��� ����������� ����� ������ �������� ���� � k - ����� ������� ���������.
//�������� �������, ������� �������� ����������� ������������� ��� �������� ������ �����.
//����������� ������ �����������.

//16 158A1 12D5 (?145CC?) 88225 - 4821 = 83404