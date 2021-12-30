#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}pNode;

typedef struct linkedList
{
	pNode* head;
	pNode* before;
	pNode* current;
}List;

void Init(List* plist)
{
	plist->head = NULL;
	plist->before = NULL;
	plist->current = NULL;
}

void LinkedInsert(List* plist, int data)
{
	pNode* newnode = (pNode*)malloc(sizeof(pNode));

	newnode->data = data;

	newnode->next = plist->head;
	plist->head = newnode;
}

int LinkedRemove(List* plist, int data)
{
	if (plist->head == NULL)
	{
		return 0;
	}
	plist->current = plist->head;
	while (plist->current != NULL)
	{
		if (plist->current->data == data)
		{
			if (plist->current == plist->head)
			{
				plist->head = plist->current->next;
			}
			else
			{
				plist->before->next = plist->current->next;
			}
			free(plist->current);
			return 1;
		}
		else
		{
			plist->before = plist->current;
			plist->current = plist->current->next;
		}
	}
	return 0;
}

void display(List* plist)
{
	plist->current = plist->head;
	while (plist->current != NULL)
	{
		printf("%d -> ", plist->current->data);
		plist->current = plist->current->next;
	}
}

void main()
{
	List* plist = (List*)malloc(sizeof(List));
	int data = 0;
	int select = 4;

	Init(plist);
	while (select != 0)
	{
		printf("1)���� 2)���� 3)��� 0)����\n");
		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
			printf("�Է°� : ");
			scanf_s("%d", &data);
			LinkedInsert(plist, data);
			break;
		case 2:
			printf("������ �� : ");
			scanf_s("%d", &data);
			if (LinkedRemove(plist, data) == 0)
			{
				printf("������ ���� �����ϴ�.\n");
			}
			else
			{
				printf("���� �Ϸ�\n");
			}
			break;
		case 3:
			display(plist);
			break;
		default:
			break;
		}
	}

}