#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//���Ḯ��Ʈ ����
typedef int element;
//��� ����ü
typedef struct _StackNode
{
	element data;
	struct StackNode* link;
}StackNode;
//top����ü
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
//���̸� ����ִ�.
int is_empty(LinkedStack *L)
{
	return (L->top == NULL);
}

element pop(LinkedStack* L)
{
	if (is_empty(L))
	{
		fprintf(stderr, "������ ����ֽ��ϴ�.\n");
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
			fprintf(stderr, "������ ����ֽ��ϴ�.\n");
	}
}

element peek(LinkedStack* L)
{
	if (is_empty(L))
	{
		fprintf(stderr, "������ ����ֽ��ϴ�.\n");
	}
	else
	{
		StackNode* temp = L->top;
		if (temp->link != NULL) {
			int data = temp->data;
			
			return data;
		}
		else
			fprintf(stderr, "������ ����ֽ��ϴ�.\n");
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