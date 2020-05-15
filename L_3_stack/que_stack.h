#ifndef QUE_STACK_H
#define _CRT_SECURE_NO_WARNINGS
#define QUE_STACK_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define TASKS_NUM 15
#define TASKS_MIN_T 1000
#define TASKS_MAX_T 2000
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
} Proc;



#endif // !QUE_STACK_H

