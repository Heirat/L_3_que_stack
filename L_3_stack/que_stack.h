#ifndef QUE_STACK_H
#define _CRT_SECURE_NO_WARNINGS
#define QUE_STACK_H
#include <stdio.h>
#define MAX_ERR 100
// Задача
struct task
{
	int num, time;
	struct task *next;
};
typedef struct stack 
{ 
	struct task *top; 
} Stack;

typedef struct queue 
{ 
	struct task *top, *last;
} Queue;

// Процессор
typedef struct proc
{
	int on, time; // Текущая задача: наличие и требуемое время
	int start, cur, dif;
} Proc;



#endif // !QUE_STACK_H

