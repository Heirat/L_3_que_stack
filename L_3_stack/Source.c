/*
Червинский Артём, ИВТ-13БО. Лабораторная работа №3. Стеки, очереди.

Организовать работу системы из очереди задач Q, трех процессоров Pi, стека S.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include "que_stack.h"


// Вывод очереди
int Print_tasks (Queue **Q)
{
	struct task *cur;
	int i;
	printf ("Начальная очередь задач:\n");
	for (i = 0, cur = (*Q)->first; i < (*Q)->cnt; i++, cur = cur->next)
	{
		printf ("%d) №%d - %d мс\n", i, cur->num, cur->time);
	}
	return 0;
}

// Закончил ли процессор выполнение задачи
void P_check (Proc *P)
{
	if (P->on == 0)
	{
		P->cur = clock();
		P->dif = P->cur - (P)->start;
		if (P->dif >= P->time)
			P->on = 0;
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
	P->start = clock();	
}

// Выбирает процессор и назначает ему задачу
void P_switch_start_task (struct task *cur, Proc *P1, Proc *P2, Proc *P3)
{
	switch (cur->num)
	{
	case 1:
		P_start_task (cur, P1);
	case 2:
		P_start_task (cur, P2);
	case 3:
		P_start_task (cur, P3);
	}
}

// Обработка задач в стеке
void S_handle (Stack **S, Proc *P1, Proc *P2, Proc *P3)
{
	struct task *cur;	
	if (!S_is_empty (*S))
	{
		if (!P_is_on ((*S)->first->num, P1, P2, P3))
		{
			// Достаем задачу из стека и назначаем процессору
			// В стеке задачи одного типа, поэтому без цикла
			cur = S_pop (S);
			P_switch_start_task (cur, P1, P2, P3); 
		}
	}
}

// Можно ли добавить задачу номера num в стек
int S_can_push (int num, Stack *S)
{	
	return S_is_empty(S) || num == S->first->num;
}

// Обработка задач в очереди
void Q_handle (Queue **Q, Stack **S, Proc *P1, Proc *P2, Proc *P3)
{
	struct task *cur;

	if (!Q_is_empty (*Q))
	{
		// Проверяем на свободу процессор для верхней задачи		
		int Q_num = (*Q)->first->num;
		// Задачи разного типа - поэтому распределяем в цикле,
		// пока есть задачи, процессоры свободны и
		// можем отправить задачи в стек
		while (!Q_is_empty (*Q) && (!P_is_on (Q_num, P1, P2, P3) || S_can_push (Q_num, *S)))
		{			
			if (!P_is_on (Q_num, P1, P2, P3))
			{
				cur = Q_pop (Q);
				P_switch_start_task (cur, P1, P2, P3);
			}
			else if (S_can_push (Q_num, *S))
			{
				cur = Q_pop (Q);
				S_push (S, cur);
			}
			if (!Q_is_empty (*Q))
				Q_num = (*Q)->first->num;
		}
	}
}

// Инициализация структур
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

void P_print (Proc *P1, Proc *P2, Proc *P3)
{

}

int Main_cycle (Queue **Q, Stack **S, Proc *P1, Proc *P2, Proc *P3)
{
	printf("Главный цикл\n");
	
	while (((*Q)->cnt > 0) || ((*S)->cnt > 0))
	{
		P_check (P1);		
		P_check (P2);
		P_check (P3);
		P_print (P1, P2, P3);
		
		S_handle (S, P1, P2, P3);		
		Q_handle (Q, S, P1, P2, P3);

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
		printf("Ошибка при инициализации структур");
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
