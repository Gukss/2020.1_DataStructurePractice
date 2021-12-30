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
			printf("찾을 값이 없습니다.");
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
	printf("삭제 성공");
	return 1;
}

void main() {
	List list;
	int select = 1;
	int data = 0;
	CInitLinkedList(&list);
	while (select != 4) {
		printf("1)삽입 2)삭제 3)출력 4)종료\n------------\n");
		scanf_s("%d", &select);
		switch (select)
		{
		case 1: //삽입
			printf("추가할 값 : ");
			scanf_s("%d", &data);
			CInsertLinkedList(&list, data);
			break;
		case 2: //삭제
			printf("삭제할 값 :");
			scanf_s("%d", &data);
			DeleteNode(&list, data);
			break;
		case 3: //출력
			display(&list);
			break;
		case 4: //종료
			break;
		default:
			break;
		}
	}
}