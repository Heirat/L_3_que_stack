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

int Init (Queue **Q, Stack **S, Proc **P1, Proc **P2, Proc **P3)
{
	return 0;
}

int Main_cycle (Queue **Q, Stack **S, Proc **P1, Proc **P2, Proc **P3)
{
	printf("Главный цикл\n");
	return 0;
}

int main() {
	setlocale(LC_ALL, "RUS");
	Stack *S = NULL;
	Queue *Q = NULL;
	Proc *P1 = NULL, *P2 = NULL, *P3 = NULL;


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
