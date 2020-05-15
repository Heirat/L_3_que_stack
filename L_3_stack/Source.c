/*
���������� ����, ���-13��. ������������ ������ �3. �����, �������.

������������ ������ ������� �� ������� ����� Q, ���� ����������� Pi, ����� S.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include "que_stack.h"

int Init (Queue **Q, Stack **S, Proc *P1, Proc *P2, Proc *P3)
{
	S_create (S);
	Q_create (Q);
	P_create (P1);
	P_create (P2);
	P_create (P3);

	Load_tasks (Q);
	Print_tasks (Q);

	return 0;
}

int Main_cycle (Queue **Q, Stack **S, Proc *P1, Proc *P2, Proc *P3)
{
	printf("������� ����\n");
	
	while (((*Q)->cnt > 0) || ((*S)->cnt > 0))
	{
		P_check (P1);
		P_check (P2);
		P_check (P3);
	}

	return 0;
}

int main() {
	setlocale(LC_ALL, "RUS");
	Stack *S = NULL;
	Queue *Q = NULL;
	Proc P1, P2, P3;


	if (Init (&Q, &S, &P1, &P2, &P3))
	{
		printf("������ ��� ������������� ��������");
		system("pause");
		return 0;
	}

	if (Main_cycle (&Q, &S, &P1, &P2, &P3))
	{		
		system("pause");
		return 0;
	}

	system("pause");
	return 0;
}
