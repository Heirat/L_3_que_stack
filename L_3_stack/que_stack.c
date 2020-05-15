#define _CRT_SECURE_NO_WARNINGS
#include "que_stack.h"

// Создание стека
int S_create (Stack **S)
{
	Stack *new_s = malloc (sizeof (Stack));
	new_s->first = NULL;
	new_s->cnt = 0;
	
	if (*S == NULL)
	{
		*S = new_s;
	}
	return 0;
}

// Создание очереди
int Q_create (Queue **Q)
{
	Queue *new_q = malloc (sizeof (Queue));
	new_q->first = NULL;
	new_q->last = NULL;
	new_q->cnt = 0;

	if (*Q == NULL)
	{
		*Q = new_q;
	}
	return 0;
}

// Создание процессора
int P_create (Proc *P)
{
	P->on = 0;
	return 0;
}


int Get_rand_range_int (int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int Gen_task (struct task *cur)
{
	int a;	
	cur->next = NULL;
	cur->num = Get_rand_range_int (1, 3);
	do	
		a = Get_rand_range_int (TASKS_MIN_T, TASKS_MAX_T);
	while (a % TASKS_STEP_T != 0);

	cur->time = a;
	return 0;
}

// Заполнение очереди
int Load_tasks (Queue **Q)
{
	struct task *cur, *last;
	srand (time(NULL));
	last = malloc (sizeof(struct task));
	int i, j;
	
	for (i = 0; i < TASKS_NUM; i++)
	{
		cur = malloc (sizeof(struct task));
		Gen_task (cur);
		if ((*Q)->first == NULL) {
			(*Q)->first = cur;
			(*Q)->last = cur;
		}
		else
		{
			(*Q)->last->next = cur;
			(*Q)->last = (*Q)->last->next;
		}
	}
	(*Q)->cnt = TASKS_NUM;
	return 0;
}


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

// Проверка процессора на выполнение задачи
int P_check (Proc *P)
{

}
