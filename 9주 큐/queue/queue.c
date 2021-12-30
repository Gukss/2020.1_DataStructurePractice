#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define Max_Q_Size 10
char queue[Max_Q_Size];
int front, rear;

void init()
{
	front = 0;
	rear = 0;
}

int Full()
{
	return ((rear + 1) % Max_Q_Size == front);
}

int Empty()
{
	return (front == rear);
}

void Display()
{
	for (int temp = front + 1; temp % Max_Q_Size != (rear + 1) % Max_Q_Size;)
	{
		printf("%3c", queue[temp]);
		temp = (temp + 1) % Max_Q_Size;
	}
	printf("\n\n");
}

void Enqueue(char item)
{
	if (Full())
	{
		printf("큐가 포화상태입니다.\n");
		return;
	}
	rear = (rear + 1) % Max_Q_Size;
	queue[rear] = item;
	Display();
}

char Dequeue()
{
	if (Empty())
	{
		printf("큐가 공백상태 입니다.\n");
		return -1;
	}
	front = (front + 1) % Max_Q_Size;
	Display();
	return queue[front];
}

void main()
{
	init();
	char alpha = 'a';

	for (int i = 0; i < 10; i++)
	{
		Enqueue(alpha+i);
	}
	printf("-----------------\n");
	printf("\nDequeue : %c \n", Dequeue());
}