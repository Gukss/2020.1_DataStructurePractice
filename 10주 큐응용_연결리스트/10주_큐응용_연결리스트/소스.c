#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef char element;
//���� ���
typedef struct _Stack
{
	element st_data;
	struct Stack* st_link;
}Stack;
//
typedef struct _LinkedStack
{
	Stack* top;
}LinkedStack;
//ť ���
typedef struct _Queue
{
	element qu_data;
	struct Queue* qu_link;
}Queue;

typedef struct _LinkedQueue
{
	 Queue* front;
	 Queue* rear;
}LinkedQueue;
//���� �ʱ�ȭ
void St_Init(LinkedStack* st)
{
	st->top == NULL;
}
//ť �ʱ�ȭ
void Qu_Init(LinkedQueue* qu)
{
	qu->front = qu->rear = NULL;
}
//st�޸� �Ҵ� �������� Ȯ��
int St_Is_Full()
{
	return ((Stack*)malloc(sizeof(Stack)) == NULL);
}
//st������� Ȯ��
int St_Is_Empty(LinkedStack* st)
{
	return (st->top == NULL);
}
//qu������� Ȯ��
int Qu_Is_Empty(LinkedQueue* qu)
{
	return (qu->front == NULL);
}
//qu�޸� �Ҵ� �������� Ȯ��
int Qu_Is_Full()
{
	return ((Queue*)malloc(sizeof(Queue)) == NULL);
}
//Push
void Push(LinkedStack* st, element item)
{
	if (St_Is_Full())
	{
		printf("������ ���� á���ϴ�.\n");
		return;
	}
		Stack* temp = (Stack*)malloc(sizeof(Stack));
		temp->st_data = item;
		temp->st_link = st->top;
		st->top = temp;
}
//Enqueue
void Enqueue(LinkedQueue* qu, element item)
{
	if (Qu_Is_Full())
	{
		printf("ť�� ���� á���ϴ�.\n");
		return;
	}
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	temp->qu_data = item;
	temp->qu_link = NULL;
	if (Qu_Is_Empty(qu))
	{
		qu->front = temp;
		qu->rear = temp;
	}
	else
	{
		qu->rear->qu_link = temp;
		qu->rear = temp;
	}
}
//Pop
element Pop(LinkedStack* st)
{
	if (St_Is_Empty(st))
	{
		printf("������ ������ϴ�.\n");
		return;
	}
	else
	{
		Stack* temp = st->top;
		element data = temp->st_data;
		st->top = st->top->st_link;
		free(temp);
		return data;
	}
}
//Dequeue
element Dequeue(LinkedQueue* qu)
{
	if (Qu_Is_Empty(qu))
	{
		printf("ť�� ������ϴ�.\n");
		return;
	}
	else
	{
		Queue* temp = qu->front;
		element data = temp->qu_data;
		qu->front = qu->front->qu_link;
		free(temp);
		return data;
	}
}
//������Լ�
int Match(LinkedStack* st, LinkedQueue* qu)
{
	element st_ch, qu_ch;
	while ((st->top != NULL) && (qu->front != NULL))
	{
		st_ch = Pop(st);
		qu_ch = Dequeue(qu);
		if (st_ch != qu_ch)
		{
			return 0;
		}
	}
	return 1;
}

void main()
{
	LinkedStack st;
	LinkedQueue qu;
	St_Init(&st); Qu_Init(&qu);

	element data[MAX_SIZE];

	printf("�ܾ� �Է� : ");
	scanf_s("%s", data);

	int len = strlen(data);
	for (int i = 0; i < len; i++)
	{
		Push(&st, data[i]);
		Enqueue(&qu, data[i]);
	}

	if (Match(&st, &qu))
	{
		printf("%s �� ȸ���Դϴ�.\n", data);
	}
	else
	{
		printf("%s �� ȸ���� �ƴմϴ�.\n",data);
	}
}