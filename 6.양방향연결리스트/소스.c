#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* prev;
	struct _node* next;
}Node;

typedef struct _DLinkedList {
	Node* head;
	Node* current;
}List;

DIntLinkedList(List* list)
{
	list->head = NULL;
	list->current = NULL;
}

void DInsertLinkedList(List* list, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	newnode->prev = NULL;
	newnode->next = NULL;
	
	if (list->head == NULL)
	{
		list->head = newnode;
	}
	else
	{
		newnode->next = list->head;
		list->head->prev = newnode;
		list->head = newnode;
	}
}

void display(List* list)
{
	list->current = list->head;

	if(list->head==NULL)
	{
		printf("노드가 없습니다.\n");
	}
	printf("오른쪽 진행");
	while (list->current->next != NULL)
	{
		printf("%d ->", list->current->data);
		list->current = list->current->next;
	}
	printf("%d\n", list->current->data);

	printf("왼쪽 진행\n");
	while (list->current->prev != NULL)
	{
		printf("%d ->", list->current->data);
		list->current = list->current->prev;
	}
	printf("%d \n", list->current->data);
}

int DeletNode(List* list, int data)
{
	if (list->head == NULL)
	{
		printf("노드가 없습니다.\n");
			return 0;
	}
	list->current = list->head;
	while (list->current != NULL) //current가 삭제할것
	{
		if (list->current->data == data)
		{
			if (list->current == list->head) //head 일때
			{
				list->head = list->current->next;
				list->head->prev = NULL;
			}
			else if(list->current->next == NULL) //마지막노드일때
			{
				list->current->prev->next = NULL;
			}
			else //가운데 꼈을때
			{
				list->current->prev->next = list->current->next;
				list->current->next->prev = list->current->prev;
			}
			free(list->current);
			return 1;
		}
		else
		{
			list->current = list->current->next;
		}
	}
}

void main()
{
	List list;
	int select = 0, data = 0;
	DIntLinkedList(&list);
	while (select != 4)
	{
		printf("1)추가 2)삭제 3)출력 4)종료\n-----------\n");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1://추가
			printf("값입력 :");
			scanf_s("%d", &data);
			DInsertLinkedList(&list, data);
			break;
		case 2://삭제
			printf("삭제할값입력 :");
			scanf_s("%d", &data);
			DeletNode(&list, data);
			break;
		case 3://출력
			display(&list);
			break;
		case 4://종료
			break;
		default:
			break;
		}

	}
}