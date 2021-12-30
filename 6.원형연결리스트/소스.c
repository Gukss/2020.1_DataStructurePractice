#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct _node {
	int data;
	struct _node* next;
}Node;
typedef struct _List {
	Node* tail;
	Node* before;
	Node* current;
	int count;
}List;

void CInitLinkedList(List* list) {
	list->tail = NULL;
	list->before = NULL;
	list->current = NULL;
	list->count = 0;
}
void CInsertLinkedList(List* list, int data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;

	if (list->tail == NULL) {
		list->tail = newnode;
		newnode->next = newnode;
	}
	else {
		newnode->next = list->tail->next;
		list->tail->next = newnode;
	}
	(list->count)++;
}

void display(List* list) {
	list->current = list->tail->next;
	while (list->current != list->tail) {
		printf("%d ->", list->current->data);
		list->current = list->current->next;
	}
	printf("%d\n", list->current->data);
	return 0;
}

int DeleteNode(List* list, int data) {
	list->current = list->tail->next;
	list->before = list->tail;
	while (list->current->data != data)
	{
		if (list->current == list->tail)
		{
			printf("ã�� ���� �����ϴ�.");
			return 0;
		}
		list->before = list->current;
		list->current = list->current->next;
	}
	if (list->current == list->tail)
	{
		list->before->next = list->current->next; 
		list->tail = list->before;
	}
	else
	{
		list->before->next = list->current->next;
	}
	free(list->current);
	printf("���� ����");
	return 1;
}

void main() {
	List list;
	int select = 1;
	int data = 0;
	CInitLinkedList(&list);
	while (select != 4) {
		printf("1)���� 2)���� 3)��� 4)����\n------------\n");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1: //����
			printf("�߰��� �� : ");
			scanf_s("%d", &data);
			CInsertLinkedList(&list, data);
			break;
		case 2: //����
			printf("������ �� :");
			scanf_s("%d", &data);
			DeleteNode(&list, data);
			break;
		case 3: //���
			display(&list);
			break;
		case 4: //����
			break;
		default:
			break;
		}
	}
}