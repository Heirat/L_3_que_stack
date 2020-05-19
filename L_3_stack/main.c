/*
���������� ����, ���-13��. ������������ ������ �3. �����, �������.

������������ ������ ������� �� ������� ����� Q, ���� ����������� Pi,
����� S. ���. �������: � ���� ����� � ����� ����� ���������� 
������ ������ ������ ���� (�� ��������������).
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include "que_stack.h"
#include "proc.h"

// ����� �� �������� ������ ������ num � ����
int can_push_s (int num, Stack *S)
{
	return S_is_empty(S) || num == S->first->num;
}

/* ������� ������� */

// ��������� ����� � �����
void S_handle (Stack **S, Proc *P1, Proc *P2, Proc *P3)
{
	struct task *cur;	
	if (!S_is_empty (*S))
	{
		if (!P_is_on ((*S)->first->num, P1, P2, P3))
		{
			// ������� ������ �� ����� � ��������� ����������
			// � ����� ������ ������ ����, ������� ��� �����
			cur = S_pop (S);			
			P_switch_start_task (cur, P1, P2, P3); 
			printf ("������ �%d (%d��) �� ����� ��������� ��������� �%d\n", cur->num, cur->time, cur->num);
		}
	}
}

// ��������� ����� � �������
void Q_handle (Queue **Q, Stack **S, Proc *P1, Proc *P2, Proc *P3)
{
	struct task *cur;
	if (!Q_is_empty (*Q))
	{
		int Q_num = (*Q)->first->num;
		while (!Q_is_empty (*Q) && (!P_is_on (Q_num, P1, P2, P3) ||
			can_push_s (Q_num, *S)))
		{			
			if (!P_is_on (Q_num, P1, P2, P3))
			{
				cur = Q_pop (Q);
				P_switch_start_task (cur, P1, P2, P3);
				printf ("������ %d) �%d (%d��) �� ������� ��������� ��������� �%d\n",
					TASKS_NUM - (*Q)->cnt, cur->num, cur->time, cur->num);
			}
			else if (can_push_s (Q_num, *S))
			{
				cur = Q_pop (Q);
				S_push (S, cur);
				printf ("������ %d) �%d (%d��) ��������� � ���� � ������� �%d\n",
					TASKS_NUM - (*Q)->cnt, cur->num, cur->time, (*S)->cnt);
			}
			if (!Q_is_empty (*Q))
				Q_num = (*Q)->first->num;			
		}
		printf ("\n���������� ���������� �����: ������� - %d, ���� - %d\n",
		(*Q)->cnt, (*S)->cnt);
	}
}

// ������������� ��������
void Init (Queue **Q, Stack **S, Proc *P1, Proc *P2, Proc *P3)
{
	S_create (S);
	Q_create (Q);
	P_create (P1);
	P_create (P2);
	P_create (P3);

	Load_tasks (Q);
	Print_tasks (*Q);	
}

// ������� ����
void Main_cycle (Queue **Q, Stack **S, Proc *P1, Proc *P2, Proc *P3)
{
	printf("\n������� ����\n");
	while (((*Q)->cnt > 0) || ((*S)->cnt > 0) || P1->on || P2->on || P3->on)
	{
		P_check (P1);
		P_check (P2);
		P_check (P3);
		
		P_print (P1, P2, P3);
		
		S_handle (S, P1, P2, P3);
		Q_handle (Q, S, P1, P2, P3);

		if (TASKS_NUM / 2 - (*Q)->cnt < 1 && TASKS_NUM / 2 - (*Q)->cnt > -2
			|| TASKS_NUM / 4 - (*Q)->cnt < 1 && TASKS_NUM / 4 - (*Q)->cnt > -2)
			Print_tasks (*Q);
		Sleep (TASKS_STEP_T);
	}	
}

int main() {
	setlocale(LC_ALL, "RUS");
	Stack *S = NULL;
	Queue *Q = NULL;
	Proc P1, P2, P3;

	Init (&Q, &S, &P1, &P2, &P3);
	Main_cycle (&Q, &S, &P1, &P2, &P3);

	system("pause");
	return 0;
}
// ������� ����������