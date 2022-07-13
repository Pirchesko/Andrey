/* 
Encoding ANSI (for example open in Visual Studio)
��� ��� �������������� 12-�� ���� ���� �������� �� ���, ��� �� �������� ���������� ������ ��������� (lab12/lab12.c), ��
�� ������ ����������, ������ 14-�� ����� � ����� ������ ��������� ��� �������� �������� �����-�� ������������� � �����.
--------------------------------------------------
	parent						child
--------------------------------------------------
	sem_init(parent, 0, 1)
	sem_init(child, 0, 0)
	start child
--------------------------------------------------
	sem_wait(parent)			sem_wait(child)
	print						print
	sem_post(child)				sem_post(parent)
--------------------------------------------------
� ���� 14-�� �� ������������ 2 ��������-��������.
����� ��������� ������ ���������� ���� ������, ���������� ��������� ���������������� �������. 
����������� � ������ ������ ���� 0, � � ������� 1. ���� ��������. � ��� ������� ���� ������ ��������� parent, ������ ��� ������ 1.
���� ����������� �������� ������������ ��� �� ��� ��������, �� ����� ������ � ������ � ���, ��� ����� ������� �� ����� ������,
����� ������ ��������� � ����-�� sem_wait ��� sem_post, ��� ��� ���� � ���������. 
� ��������, ��� � ������, ������� ����� � ���, ��� ����� ����� � ��� �� ������� ����� � ����������� ������ ��������� ��� � �����,
� �� ����� ��� sem_wait (���� ��� ������������ � ��������� ��������� 1) ������� ����� ������� - �� ����� ����� ����� ������ ���� ���.
������� � �������� ��������, ������� ��� ����� ����� � �� ������ ����� ������� � ������ ���������� ��� (���� ������� �� ����� ������ 0)
������� ��� ���������� ������������� �� �� ������ �������� �� �������, �� ���������� ������.
����� �������� ������ ���������� ��� ��������-�������� ������������������ ������.
� ����� �������� ������������ �����, ����� ������������������� �������� ��������� ��� ����� �������� �������.
�.�. ���� ���������� ����������. 
�����: � 2-�� ��������� ������������ ���������� ������� - �� �����, � 2-�� ���������� - �����.
����� ��� 14-�� ����:
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <string.h>

#define LINES_COUNT 10

sem_t parentSem;
sem_t childSem;

void print_error(int error_code, char* argv[])
{
	char buf[256];
	strerror_r(error_code, buf, sizeof buf);
	fprintf(stderr, "%s: creating thread: %s\n", argv[0], buf);
	exit(1);
}

void printParent()
{
	for (int i = 0; i < LINES_COUNT; i++)
	{
		sem_wait(&parentSem);
		printf("Parent\n");
		sem_post(&childSem);
	}
}

void* printChild(void* arg)
{
	for (int i = 0; i < LINES_COUNT; i++)
	{
		sem_wait(&childSem);
		printf("Child\n");
		sem_post(&parentSem);
	}
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	pthread_t thread;

	sem_init(&parentSem, 0, 1);
	sem_init(&childSem, 0, 0);

	int error_code = pthread_create(&thread, NULL, printChild, NULL);
	if (error_code != 0)
	{
		print_error(error_code, argv);
	}
	printParent();

	sem_destroy(&parentSem);
	sem_destroy(&childSem);
	pthread_exit(NULL);
}
