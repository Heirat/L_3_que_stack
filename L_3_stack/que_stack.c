#define _CRT_SECURE_NO_WARNINGS
#include "que_stack.h"

// Создание стека
int S_create (Stack **S)
{

	Stack *new_s = malloc (sizeof (Stack));
	if (new_s == NULL)
		return 1;
	new_s->first = NULL;
	new_s->cnt = 0;
	
	if (*S == NULL)	
		*S = new_s;
	
	return 0;
}

// Создание очереди
int Q_create (Queue **Q)
{
	// Проверить
	Queue *new_q = malloc (sizeof (Queue));
	if (new_q == NULL)
		return 1;
	new_q->first = NULL;
	new_q->last = NULL;
	new_q->cnt = 0;

	if (*Q == NULL)	
		*Q = new_q;	
	return 0;
}


/* Функции стека */

// Проверка на пустоту стека
int S_is_empty (Stack *S)
{
	return S->first == NULL;
}

//Возвращает задачу из стека и удаляет ее
struct task *S_pop (Stack **S)
{
	struct task *res;

	res = (*S)->first;
	(*S)->first = (*S)->first->next;
	(*S)->cnt--;
	return res;
}

//Помещает задачу в стек
void S_push (Stack **S, struct task *t)
{
	t->next = (*S)->first;
	(*S)->first = t;
	(*S)->cnt++;
}

/* Функции очереди */

// Вывод очереди
void Print_tasks (Queue *Q)
{
	struct task *cur;
	int i;
	printf ("\nОчередь задач:\n");
	for (i = 0, cur = Q->first; i < Q->cnt; i++, cur = cur->next)
		printf ("%d) №%d - %d мс\n", TASKS_NUM - Q->cnt + i + 1, cur->num, cur->time);
}

// Проверка на пустоту очереди
int Q_is_empty (Queue *Q)
{
	return Q->first == NULL;
}

// Добавлнеие задачи в очередь
void Q_push (Queue **Q, struct task *t)
{
	if ((*Q)->first == NULL)
	{
		(*Q)->first = t;
		(*Q)->last = t;
	}
	else
	{
		(*Q)->last->next = t;
		(*Q)->last = (*Q)->last->next;
	}
}

//Возвращает задачу из очереди и удаляет ее
struct task *Q_pop (Queue **Q)
{
	struct task *res;

	res = (*Q)->first;
	(*Q)->first = (*Q)->first->next;
	(*Q)->cnt--;
	return res;
}

// Случайное число
int Get_rand_range_int (int min, int max)
{
	return rand() % (max - min + 1) + min;
}

// Создание случайной задачи
int Gen_task (struct task *cur)
{
	int a;	
	cur->next = NULL;
	cur->num = Get_rand_range_int (1, 3);
	
	a = Get_rand_range_int (TASKS_MIN_T, TASKS_MAX_T) * TASKS_STEP_T;	

	cur->time = a;
	return 0;
}

// Заполнение очереди
int Load_tasks (Queue **Q)
{
	struct task *cur, *last;
	srand (time(NULL));
	last = malloc (sizeof(struct task));
	if (last == NULL)
		return 1;
	int i;
	
	for (i = 0; i < TASKS_NUM; i++)
	{
		// Создание случайной задачи и добавление в очередь
		cur = malloc (sizeof(struct task));
		if (cur == NULL)
			return 1;
		Gen_task (cur);
		Q_push (Q, cur);
	}
	(*Q)->cnt = TASKS_NUM;
	return 0;
}
