#ifndef QUE_STACK_H
#define _CRT_SECURE_NO_WARNINGS
#define QUE_STACK_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_ERR 100
#define TASKS_NUM 15
#define TASKS_MIN_T 100
#define TASKS_MAX_T 1000
#define TASKS_STEP_T 10
// Задача
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

// Процессор
typedef struct proc
{
	int on, time; // Текущая задача: наличие и требуемое время
	int start, cur, dif;
} Proc;



#endif // !QUE_STACK_H

