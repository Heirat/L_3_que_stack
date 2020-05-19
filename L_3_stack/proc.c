#define _CRT_SECURE_NO_WARNINGS
#include "proc.h"
#include "que_stack.h"

// Выводит состояние процессоров
void P_print (Proc *P1, Proc *P2, Proc *P3)
{
	int i;
	printf ("\n");
	for (i = 0; i < 3; i++)
	{
		printf ("Процессор %d: ", i + 1);
		switch (i)
		{
		case 0:
			if (P1->on == 0)
				printf ("свободен\n");
			else
				printf ("работает: %d/%d мс\n", P1->dif, P1->time);
			break;
		case 1:
			if (P2->on == 0)
				printf ("свободен\n");
			else
				printf ("работает: %d/%d мс\n", P2->dif, P2->time);
			break;
		case 2:
			if (P3->on == 0)
				printf ("свободен\n");
			else
				printf ("работает: %d/%d мс\n", P3->dif, P3->time);
			break;
		}
	}
	printf ("\n");
}

// Создание процессора
int P_create (Proc *P)
{
	P->on = 0;
	P->cur = -1;
	P->dif = -1;
	P->start = -1;
	P->time = -1;
	P->t = NULL;
	return 0;
}

// Проверить и закончить задачу
void P_check (Proc *P)
{
	if (P->on == 1)
	{
		P->cur = clock();
		P->dif = P->cur - (P)->start;
		if (P->dif >= P->time)
		{
			P->on = 0;
			free (P->t);
		}
	}
}

// Включен ли процессор с номерм num
int P_is_on (int num, Proc *P1, Proc *P2, Proc *P3)
{
	switch (num)
	{
	case 1:
		return P1->on;
	case 2:
		return P2->on;
	case 3:
		return P3->on;
	default:
		return 0;
	}
}

// Назначает задачу процессору
void P_start_task (struct task *cur, Proc *P)
{
	P->on = 1;
	P->time = cur->time;
	P->t = cur;
	P->start = clock();
}

// Выбирает процессор и назначает ему задачу
void P_switch_start_task (struct task *cur, Proc *P1, Proc *P2, Proc *P3)
{
	switch (cur->num)
	{
	case 1:
		P_start_task (cur, P1);
		break;
	case 2:
		P_start_task (cur, P2);
		break;
	case 3:
		P_start_task (cur, P3);
		break;
	}
}
