#ifndef PROC_H
#define _CRT_SECURE_NO_WARNINGS
#define PROC_H
#include <stdio.h>
#include <stdlib.h>

// ���������
typedef struct proc
{
	int on, time; // ������� ������: ������� � ��������� �����
	int start, cur, dif;
	struct task *t; // ��������� �� ������
} Proc;


// �������� ����������
int P_create (Proc *P);

// ������� ��������� �����������
void P_print (Proc *P1, Proc *P2, Proc *P3);

// ��������� � ��������� ������
void P_check (Proc *P);

// ������� �� ��������� � ������ num
int P_is_on (int num, Proc *P1, Proc *P2, Proc *P3);

// ��������� ������ ����������
void P_start_task (struct task *cur, Proc *P);

// �������� ��������� � ��������� ��� ������
void P_switch_start_task (struct task *cur, Proc *P1, Proc *P2, Proc *P3);

#endif // !PROC_H
#pragma once
