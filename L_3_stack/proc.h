#ifndef PROC_H
#define _CRT_SECURE_NO_WARNINGS
#define PROC_H
#include <stdio.h>
#include <stdlib.h>

// Процессор
typedef struct proc
{
	int on, time; // Текущая задача: наличие и требуемое время
	int start, cur, dif;
	struct task *t; // Указатель на задачу
} Proc;


// Создание процессора
int P_create (Proc *P);

// Выводит состояние процессоров
void P_print (Proc *P1, Proc *P2, Proc *P3);

// Проверить и закончить задачу
void P_check (Proc *P);

// Включен ли процессор с номерм num
int P_is_on (int num, Proc *P1, Proc *P2, Proc *P3);

// Назначает задачу процессору
void P_start_task (struct task *cur, Proc *P);

// Выбирает процессор и назначает ему задачу
void P_switch_start_task (struct task *cur, Proc *P1, Proc *P2, Proc *P3);

#endif // !PROC_H
#pragma once
