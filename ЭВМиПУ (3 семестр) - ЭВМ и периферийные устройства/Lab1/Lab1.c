#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 74250

int main()
{
    //����������� ����������
    int massive[N]; //������ ������� ����� �����������
    int start; //������������ ������� ������ ����������
    int finish; //������������ ������� ����� ����������

    //������ ������ � ���������� ���������� � �������
    srand(1);
    for (int i = 0; i < N; i++)
    {
        massive[i] = rand();
    }

    //��������� ���������
    printf("Start sort...\n");
    start = clock();
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if (massive[i] < massive[j])
            {
                int temp = massive[i];
                massive[i] = massive[j];
                massive[j] = temp;
            }
        }
    }
    finish = clock();
    printf("Finish!\n");

    //������� �����
    printf("Time = %d\n", (finish - start));
    return 0;
}
