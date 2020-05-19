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

// Создание стека
int S_create (Stack **S);

// Создание очереди
int Q_create (Queue **Q);

/* Функции стека */

// Проверка на пустоту стека
int S_is_empty (Stack *S);

//Возвращает задачу из стека и удаляет ее
struct task *S_pop (Stack **S);

//Помещает задачу в стек
void S_push (Stack **S, struct task *t);

/* Функции очереди */

// Вывод очереди
void Print_tasks (Queue *Q);

// Проверка на пустоту очереди
int Q_is_empty (Queue *Q);

// Добавлнеие задачи в очередь
void Q_push (Queue **Q, struct task *t);

//Возвращает задачу из очереди и удаляет ее
struct task *Q_pop (Queue **Q);

// Случайное число
int Get_rand_range_int (int min, int max);

// Создание случайной задачи
int Gen_task (struct task *cur);

// Заполнение очереди
int Load_tasks (Queue **Q);
#endif // !QUE_STACK_H

