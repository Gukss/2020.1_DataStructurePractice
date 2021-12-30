#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���� �ִ� ����
#define MAX_SIZE 100
typedef double element;
element stack[MAX_SIZE];
int top = -1;

int isFull()
{
	return (top == MAX_SIZE - 1);
}
int isEmpty()
{
	return (top == -1);
}
element push(element item)
{
	if (isFull())
	{
		printf("������ ���� ��\n");
		return -1;
	}
	top++;
	stack[top] = item;
	return 1;
}
element pop()
{
	if (isEmpty())
	{
		printf("������ �����\n");
		return -1;
	}
	return stack[top--];
}

R_paren(char *postfix, int* p_top)
{
	char temp;
	while (1)
	{
		temp = pop();
		if (temp != '(')
		{
			postfix[*p_top] = temp;
			(*p_top)++;
		}
		else
		{
			break;
		}
	}
}

int E(char temp)
{
	switch (temp)
	{
	case '+':
	case '-':
		return 1;
		break;
	case '*':
	case '/':
		return 2;
		break;
	default:
		return 0;
		break;
	}
}

void oper(char* postfix, int* p_top, char temp)
{
	if (E(temp) <= E(stack[top]))
	{
		postfix[*p_top] = pop();
		(*p_top)++;
	}
	push(temp);
}

void Infix_to_Postfix(char *infix, char *postfix)
{
	int len = strlen(infix);
	int p_top = 0;
	char temp;

	//������
	for (int i = 0; i < len; i++)
	{
		temp = infix[i];

		switch (temp)
		{
		case '(':
			push(temp);
			break;
		case ')':
			R_paren(postfix, &p_top);
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			oper(postfix, &p_top, temp);
			break;
		default:
			postfix[p_top] = temp;
			p_top++;
			break;
		}
	}
	
	while (top != -1)
	{
		postfix[p_top] = pop();
		p_top++;
	}
	postfix[p_top] = NULL;
}

double Result(char* postfix)
{
	double A, B;
	int len = strlen(postfix);
	char temp;

	for (int i = 0; i < len; i++)
	{
		temp = postfix[i];
		if (temp >= '0' && temp <= '9')
		{
			push(temp - 48);
		}
		else
		{
			B = pop();
			A = pop();
			switch (temp)
			{
			case '+':
				push(A + B);
				break;
			case '-':
				push(A - B);
				break;
			case '*':
				push(A * B);
				break;
			case '/':
				push(A / B);
				break;
			default:
				break;
			}
		}
	}
	return pop();
}

void main()
{
	char infix[MAX_SIZE];
 	char postfix[MAX_SIZE];
	while (1)
	{
		printf("������ �Է� : ");
		scanf_s("%s", infix);
		Infix_to_Postfix(infix,postfix);
		printf("\n\n���\n%s\n", postfix);
		printf("���� ��� : %lf\n\n", Result(postfix));
	}

}