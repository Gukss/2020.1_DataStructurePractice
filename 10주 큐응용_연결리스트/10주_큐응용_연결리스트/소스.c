#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef char element;
//스택 노드
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
//큐 노드
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
//스택 초기화
void St_Init(LinkedStack* st)
{
	st->top == NULL;
}
//큐 초기화
void Qu_Init(LinkedQueue* qu)
{
	qu->front = qu->rear = NULL;
}
//st메모리 할당 가능한지 확인
int St_Is_Full()
{
	return ((Stack*)malloc(sizeof(Stack)) == NULL);
}
//st비었는지 확인
int St_Is_Empty(LinkedStack* st)
{
	return (st->top == NULL);
}
//qu비었는지 확인
int Qu_Is_Empty(LinkedQueue* qu)
{
	return (qu->front == NULL);
}
//qu메모리 할당 가능한지 확인
int Qu_Is_Full()
{
	return ((Queue*)malloc(sizeof(Queue)) == NULL);
}
//Push
void Push(LinkedStack* st, element item)
{
	if (St_Is_Full())
	{
		printf("스택이 가득 찼습니다.\n");
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
		printf("큐가 가득 찼습니다.\n");
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
		printf("스택이 비었습니다.\n");
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
		printf("큐가 비었습니다.\n");
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
//문장비교함수
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

	printf("단어 입력 : ");
	scanf_s("%s", data);

	int len = strlen(data);
	for (int i = 0; i < len; i++)
	{
		Push(&st, data[i]);
		Enqueue(&qu, data[i]);
	}

	if (Match(&st, &qu))
	{
		printf("%s 는 회문입니다.\n", data);
	}
	else
	{
		printf("%s 는 회문이 아닙니다.\n",data);
	}
}