#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//연결리스트 스택
typedef int element;
//노드 구조체
typedef struct _StackNode
{
	element data;
	struct StackNode* link;
}StackNode;
//top구조체
typedef struct _LinkedStack
{
	struct StackNode* top;
}LinkedStack;

void init(LinkedStack* L)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->link = NULL;
	L->top = temp;
}

int Is_Full()
{
	return ((StackNode*)malloc(sizeof(StackNode)) == NULL);
}

void push(LinkedStack *L, element item)
{
	if (Is_Full() != 1)
	{
		StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
		temp->data = item;
		temp->link = L->top;
		L->top = temp;
	}
}

void display(LinkedStack *L)
{
	for (StackNode* p = L->top; p->link != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL\n");
}
//참이면 비어있다.
int is_empty(LinkedStack *L)
{
	return (L->top == NULL);
}

element pop(LinkedStack* L)
{
	if (is_empty(L))
	{
		fprintf(stderr, "스택이 비어있습니다.\n");
	}
	else
	{
		StackNode* temp = L->top;
		if (temp->link != NULL) {
			int data = temp->data;
			printf("pop : %d\n", data);
			L->top = temp->link;
			free(temp);
			return data;
		}
		else
			fprintf(stderr, "스택이 비어있습니다.\n");
	}
}

element peek(LinkedStack* L)
{
	if (is_empty(L))
	{
		fprintf(stderr, "스택이 비어있습니다.\n");
	}
	else
	{
		StackNode* temp = L->top;
		if (temp->link != NULL) {
			int data = temp->data;
			
			return data;
		}
		else
			fprintf(stderr, "스택이 비어있습니다.\n");
	}
}

void main()
{
	LinkedStack L;
	init(&L);

	for (int i = 0; i < 6; i++) 
	{
		push(&L, rand() % 10 + 1);
		display(&L);
	}
	printf("------------------------\n");
	printf("peek : %d\n", peek(&L));
	printf("------------------------\n");
	
	for (int i = 0; i < 7; i++)
	{
		pop(&L);
		display(&L);
	}

}