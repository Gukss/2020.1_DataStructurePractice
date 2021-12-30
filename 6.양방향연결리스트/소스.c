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
		printf("��尡 �����ϴ�.\n");
	}
	printf("������ ����");
	while (list->current->next != NULL)
	{
		printf("%d ->", list->current->data);
		list->current = list->current->next;
	}
	printf("%d\n", list->current->data);

	printf("���� ����\n");
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
		printf("��尡 �����ϴ�.\n");
			return 0;
	}
	list->current = list->head;
	while (list->current != NULL) //current�� �����Ұ�
	{
		if (list->current->data == data)
		{
			if (list->current == list->head) //head �϶�
			{
				list->head = list->current->next;
				list->head->prev = NULL;
			}
			else if(list->current->next == NULL) //����������϶�
			{
				list->current->prev->next = NULL;
			}
			else //��� ������
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
		printf("1)�߰� 2)���� 3)��� 4)����\n-----------\n");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1://�߰�
			printf("���Է� :");
			scanf_s("%d", &data);
			DInsertLinkedList(&list, data);
			break;
		case 2://����
			printf("�����Ұ��Է� :");
			scanf_s("%d", &data);
			DeletNode(&list, data);
			break;
		case 3://���
			display(&list);
			break;
		case 4://����
			break;
		default:
			break;
		}

	}
}