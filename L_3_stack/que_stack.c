#define _CRT_SECURE_NO_WARNINGS
#include "que_stack.h"

// �������� �����
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

// �������� �������
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

// �������� ����������
int P_create (Proc *P)
{
	P->on = 0;
	P->cur = -1;
	P->dif = -1;
	P->start = -1;
	P->time = -1;
	return 0;
}


// ������� �����

// �������� �� ������� �����
int S_is_empty (Stack *S)
{
	return S->first == NULL;
}


//���������� ������ �� ����� � ������� ��
struct task *S_pop (Stack **S)
{
	struct task *res;

	res = (*S)->first;
	(*S)->first = (*S)->first->next;
	(*S)->cnt--;
	return res;
}

//�������� ������ � ����
void S_push (Stack **S, struct task *t)
{
	t->next = (*S)->first;
	(*S)->first = t;
	(*S)->cnt++;
}

// ������� �������

// �������� �� ������� �������
int Q_is_empty (Queue *Q)
{
	return Q->first == NULL;
}

// ���������� ������ � �������
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

//���������� ������ �� ������� � ������� ��
struct task *Q_pop (Queue **Q)
{
	struct task *res;

	res = (*Q)->first;
	(*Q)->first = (*Q)->first->next;
	(*Q)->cnt--;
	return res;
}


// ��������� �����
int Get_rand_range_int (int min, int max)
{
	return rand() % (max - min + 1) + min;
}

// �������� ��������� ������
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


// ���������� �������
int Load_tasks (Queue **Q)
{
	struct task *cur, *last;
	srand (time(NULL));
	last = malloc (sizeof(struct task));
	int i;
	
	for (i = 0; i < TASKS_NUM; i++)
	{
		// �������� ��������� ������ � ���������� � �������
		cur = malloc (sizeof(struct task));
		Gen_task (cur);
		Q_push (Q, cur);
	}
	(*Q)->cnt = TASKS_NUM;
	return 0;
}
