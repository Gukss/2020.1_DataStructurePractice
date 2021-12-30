#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 5
typedef int element;
element stack[STACK_SIZE];
int top = -1;

int Is_Full()
{
	//가득 찼을 경우
	if (top == STACK_SIZE-1)
		return 1;
	//빈공간 있을 경우
	else
		return 0;
}

void display()
{
	int temp = top;
	for (int i = STACK_SIZE - 1; i >= 0; i--)
	{
		printf("[%2d]  |", i);
		if (i <= temp)
		{
			if (i == temp)
			{
				printf("%3d  |  <-- top\n", stack[i]);
			}
			else 
			{
				printf("%3d  |\n", stack[i]);
			}
		}
		else
		{
			printf("     |\n");
		}
	}
	printf("       -----\n\n");
}

int Push(int data)
{
	printf("입력될 값은 %d 이다.\n", data);
	if (Is_Full())
	{
		printf("스택이 가득찼습니다.\n");
		return 0;
	}
	stack[++top] = data;
	display();
}

int Is_Empty()
{
	return (top == -1);
}

element Pop()
{
	if (Is_Empty())
	{
		printf("스택이 비었습니다.\n");
		return -1;
	}
	return stack[top--];
}

element Peek()
{
	if (Is_Empty())
	{
		printf("스택이 비었습니다.\n");
		return -1;
	}
	return stack[top];
}

void main()
{
	int temp = 0;

	for (int i = 0; i < 6; i++) {
		Push(rand() % 10 + 1);
	}
	for (int i = 0; i < 6; i++) {
		temp = Pop();
		if (temp != -1)
		{
			printf("Pop : %d\n", temp);
		}
	}
	
}