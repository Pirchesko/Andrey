#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

//�������� ������� 
typedef struct queue
{    
    int queue[100];
    int end; //������� ���������� �������� � �������
    int begin; //������� ������� �������� � �������
} queue;

//������������� �������
void init(struct queue* q)
{
    q->begin = 1;
    q->end = 0;
    return;
}

//�������� ����� �� �������
int empty(struct queue* q)
{
    if (q->end < q->begin)
    {
        return -1; //�����
    }
    else
    {
        return 1; //���� ��������
    }
}

//�������� ������� ��� ����� �������� �������
int is_empty(struct queue* q, const int** matrix, const int size, int vershina, int* status)
{
    if (empty(q) == 1)
    {
        return 1;
    }
    else
    {
        int check = 0;
        for (int i = 0; i < size; i++)
        {
            if ((matrix[vershina][i] == 1) && (status[i] == 0))
            {
                check = 1;
            }
        }
        if (check == 1)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

//���������� �������� � �������
void add(struct queue* q, int value)
{
    q->end++;
    q->queue[q->end] = value;
}

//�������� �������� �� �������
int delete(struct queue* q)
{
    int value = q->queue[q->begin];
    q->begin++;
    return value;
}

//����� ������
void print_queue(struct queue* q)
{
    int h;
    printf("�������: ");
    for (h = q->begin; h <= q->end; h++)
    {
        printf("%d ", q->queue[h]);
    }
    printf("\n\n");
    return;
}

//����� ������� ������
void print_status(const int* status, const int size)
{
    printf("������ ������: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d |'%d',  ", i, status[i]); //�� ��� �� | ��� �������, � � '' ��� ������
    }
    printf("\n");
}

//����� ������� ���������
void print_matrix(const int** matrix, const int size)
{
    printf("������� ���������: \n");
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++)
        {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//������� ���������� ����� ���������
void print_distance(const int* distance, const int size)
{
    int max_distance = 0;
    printf("\n������� | ����������\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d | %d\n", i, distance[i]);
        if (max_distance < distance[i])
        {
            max_distance = distance[i];
        }
    }
    printf("\n���������� | �������\n");
    for (int i = 0; i <= max_distance; i++)
    {
        printf("%d | ", i);
        for (int j = 0; j < size; j++)
        {
            if (distance[j] == i)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

//������������ �������� �������
void fix_input(char* text)
{
    int i = 0;
    int j = 0;
    char fix[1000];
    while ((text[i] != '\n') && (text[i] != '\0'))
    {
        if ((text[i] == '0') || (text[i] == '1'))
        {
            fix[j] = text[i];
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    fix[j] = '\0';
    for (int k = 0; k < strlen(fix); k++)
    {
        text[k] = fix[k];
    }
    text[strlen(fix)] = '\0';
}

//������ ��������� ������
void create_matrix(int **matrix, const char* text, const int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = text[i * size + j] - 48;
        }
    }
}

//������� ���������� ����� ���������
void check_distance(const int **matrix, const int size, int* distance, int vershina, int* status)
{
    for (int i = 0; i < size; i++)
    {
        if ((matrix[i][vershina] == 1) && (vershina != i))
        {
            if (distance[i] != -1)
            {
                if (distance[vershina] == -1)
                {
                    distance[vershina] = distance[i] + 1;
                }
                else if (distance[i] < distance[vershina])
                {
                    distance[vershina] = distance[i] + 1;
                }
            }
        }
    }
    if (distance[vershina] == -1)
    {
        distance[vershina] = 0;
    }
}

//�������� BFS � ��������� ����������
void bfs(const int** matrix, const int size, int vershina)
{
    //�������� ������� 
    queue* q;
    q = (queue*)malloc(sizeof(queue));
    init(q);

    //���������� �������
    int* status = (int*)malloc(size * sizeof(int)); //0 - �� ����������, 1 - ��� � ������ ����, 2 - ����������
    for (int i = 0; i < size; i++)
    {
        status[i] = 0;
    }

    //����������
    int* distance = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        distance[i] = -1;
    }

    status[vershina] = 1; //������������� ������� 0
    distance[vershina] = 0;
    print_status(status, size);
    do
    {
        //����������� �� �����
        for (int i = 0; i < size; i++)
        {
            //�� ������� ��������� ������� ��������� ������� ������� ����� �����������
            if ((matrix[vershina][i] == 1) && (status[i] == 0))
            {
                add(q, i); //� ��������� �� � �������
                status[i] = 1; //������ "� �������"
                distance[i] = distance[vershina] + 1;
            }
        }
        if (empty(q) == -1)
        {
            break;
        }
        print_queue(q); //������� �������
        status[vershina] = 2; //������� ������� ���������� ����������
        vershina = delete(q); //������� � �� �������
        print_status(status, size);//������� ������
        //check_distance(matrix, size, distance, vershina, status); //������� ����������
    } while (is_empty(q, matrix, size, vershina, status) != -1); //���� ������� �� �����
    print_distance(distance, size);
}

int main()
{
    //��������� �������� ����� � �������
    system("chcp 1251");
    system("cls");
    
    //��������� ������� ��������� � ������������ ���� � ������������ � ��� ������� � ��������� ������
    char text[1000];
    fgets(text, 1000, stdin);
    fix_input(text);

    //�������� ������� ������ ����� �������
    int vershina;
    printf("�������: ");
    if (scanf("%d", &vershina) != 1)
    {
        return 0;
    }
    printf("\n");

    //������ ������������ ������ ��� ������� ���������
    int size = sqrt(strlen(text));
    int** matrix = (int**)calloc(size, sizeof(int*));
    for (int i = 0; i < size; i++)
    {
        matrix[i] = (int*)calloc(size, sizeof(int));
    }
    
    //������ � ������� ������� ���������
    create_matrix(matrix, text, size);
    print_matrix(matrix, size);

    printf("'0' - �� ����������\n");
    printf("'1' - � �������\n");
    printf("'2' - ����������\n\n");

    //��������� �������� BFS
    bfs(matrix, size, vershina);

    free(matrix);
    return 0;
}

/*
    ���� �:
    0 1 1 0 0 0 1
    1 0 1 1 0 0 0
    1 1 0 0 0 0 0
    0 1 0 0 1 0 0
    0 0 0 1 0 1 0
    0 0 0 0 1 0 1
    1 0 0 0 0 1 0

    ���� �:
    0 1 0 1 0 0 0 0 0 0 0
    1 0 1 0 0 0 0 1 0 0 0
    0 1 0 1 0 0 0 0 1 0 0
    1 0 1 0 1 0 0 0 0 0 0
    0 0 0 1 0 1 1 0 0 0 0
    0 0 0 0 1 0 0 0 0 1 0
    0 0 0 0 1 0 0 0 0 0 0
    0 1 0 0 0 0 0 0 1 0 0
    0 0 1 0 0 0 0 1 0 1 0
    0 0 0 0 0 1 0 0 1 0 1
    0 0 0 0 0 0 0 0 0 1 0

    ���� �:
    0 0 0 0 0 0 0 0 0 1 0 0 0 0 
    0 0 0 1 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 1 0 1 0 0 0 0 0 0
    0 1 0 0 1 0 1 0 1 0 0 0 0 0
    0 0 0 1 0 0 0 0 0 0 0 0 0 0
    0 0 1 0 0 0 0 0 0 0 1 0 1 0
    0 0 0 1 0 0 0 0 1 0 0 0 0 1
    0 0 1 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 1 0 0 1 0 0 1 0 0 0 0
    1 0 0 0 0 0 0 0 1 0 0 1 0 0
    0 0 0 0 0 1 0 0 0 0 0 0 1 0
    0 0 0 0 0 0 0 0 0 1 0 0 0 1
    0 0 0 0 0 1 0 0 0 0 1 0 0 0
    0 0 0 0 0 0 1 0 0 0 0 1 0 0

    ���� �:
    0 0 1 1 0 0 0
    1 0 0 0 1 0 0
    0 1 0 0 0 0 0
    0 0 0 0 0 0 1
    0 0 0 0 0 1 0
    0 0 1 0 1 0 1
    0 0 1 1 0 0 0

    ���� �:
    0 0 1 1 0 0 0
    0 0 0 0 0 0 0
    0 1 0 0 0 1 0
    1 0 0 0 0 0 0
    0 1 0 0 0 1 0
    0 0 1 0 1 0 0
    0 0 1 1 0 0 0

    ���� �:
    0 0 0 0 0 0 0 0 0 1 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 1 0 0 0 0 0 0 0 0
    0 1 0 0 1 0 1 0 1 0 0 0 0 0
    0 0 0 1 0 0 0 0 0 0 0 0 1 0
    0 0 1 0 0 0 0 0 0 0 0 0 1 0
    0 0 0 1 0 0 0 0 0 0 0 0 0 1
    0 0 1 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 1 0 0 1 0 0 0 0
    1 0 0 0 0 0 0 0 0 0 0 1 0 0
    0 0 0 0 0 1 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 1 0 0 0 1
    0 0 0 0 0 0 0 0 0 0 1 0 0 0
    0 0 0 0 0 0 1 0 0 0 0 0 0 0
 */