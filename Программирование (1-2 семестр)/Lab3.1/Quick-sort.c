//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

//��������� ���������
void quick_sort(int* a, int first, int last)
{
	if (first < last)
	{
		int left = first;
		int right = last;
		int mid = a[(left + right) / 2];
		do
		{
			while (a[left] < mid)
			{
				left++;
			}
			while (a[right] > mid)
			{
				right--;
			}
			if (left <= right)
			{
				swap(&a[left], &a[right]);
				left++;
				right--;
			}
		} while (left <= right);
		quick_sort(a, first, right);
		quick_sort(a, left, last);
	}
}

int main()
{
	//������ ���������� ���������
	int N;
	if (scanf("%d", &N) != 1)
	{
		return 0;
	}

	//������ ������
	int* a = (int*)malloc((N + 1) * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		if (scanf("%d", &a[i]) != 1)
		{
			return 0;
		}
	}

	//��������� ������������
	quick_sort(a, 0, N - 1);

	//������� �����
	for (int i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	free(a);
	return 0;
}
