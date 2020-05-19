#ifndef QUE_STACK_H
#define _CRT_SECURE_NO_WARNINGS
#define QUE_STACK_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TASKS_NUM 15
#define TASKS_MIN_T 2
#define TASKS_MAX_T 10
#define TASKS_STEP_T 100
// ������
struct task
{
	int num, time;
	struct task *next;
};

typedef struct stack 
{ 
	struct task *first; 
	int cnt;
} Stack;

typedef struct queue 
{ 
	struct task *first, *last;
	int cnt;
} Queue;

// ���������
typedef struct proc
{
	int on, time; // ������� ������: ������� � ��������� �����
	int start, cur, dif;
	struct task *t; // ��������� �� ������
} Proc;

// �������� �����
int S_create (Stack **S);

// �������� �������
int Q_create (Queue **Q);

// �������� ����������
int P_create (Proc *P);

/* ������� ����� */

// �������� �� ������� �����
int S_is_empty (Stack *S);

//���������� ������ �� ����� � ������� ��
struct task *S_pop (Stack **S);

//�������� ������ � ����
void S_push (Stack **S, struct task *t);

/* ������� ������� */

// �������� �� ������� �������
int Q_is_empty (Queue *Q);

// ���������� ������ � �������
void Q_push (Queue **Q, struct task *t);

//���������� ������ �� ������� � ������� ��
struct task *Q_pop (Queue **Q);

// ��������� �����
int Get_rand_range_int (int min, int max);

// �������� ��������� ������
int Gen_task (struct task *cur);

// ���������� �������
int Load_tasks (Queue **Q);
#endif // !QUE_STACK_H

