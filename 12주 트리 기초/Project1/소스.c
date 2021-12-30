#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#define MAX_SIZE 9
#define A_TEMP 20
typedef struct _Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;
Node* Create(int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = data;
	return newnode;
}void Display(int temp[A_TEMP])
{
	int level = 1;
	int index = 0;
	int i = 1;
	while (i < A_TEMP)
	{
		for (int j = A_TEMP - level * 2; j >= 0; j--)
		{
			printf("   ");
		}
		while (i <= pow(2, level) - 1)
		{
			if (i < A_TEMP)
			{
				if (i % 2 == 1)
				{
					printf("%3d", temp[i]);
				}
				else
				{
					printf("   ");
					printf("%-3d", temp[i]);
				}
			}
			i++;
		}
		printf("\n\n");
		level++;
	}
}void Preorder(Node* bt)
{
	if (bt == NULL)
	{
		return;
	}
	printf("%d ->", bt->data);
	Preorder(bt->left);
	Preorder(bt->right);
}void Inorder(Node* bt)
{
	if (bt == NULL)
	{
		return;
	}
	Preorder(bt->left);
	printf("%d ->", bt->data);
	Preorder(bt->right);
}void Postorder(Node* bt)
{
	if (bt == NULL)
	{
		return;
	}
	Preorder(bt->left);
	Preorder(bt->right);
	printf("%d ->", bt->data);
}int main(void)
{
	Node* tree[MAX_SIZE], * root, * current;
	int temp[A_TEMP] = { 0, 1};
	int i = 0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		tree[i] = Create(i + 1);
	}
	root = tree[0];
	for (i = 1; i < MAX_SIZE; i++)
	{
		//flag = 반복을 할지 말지 count = 출력을 위하여 
		int flag = 1, count = 1;
		current = root;
		while (flag)
		{
			switch (rand() % 2)
			{
			case 0:
				if (current->left == NULL)
				{
					current->left = tree[i];
					flag = 0;
					count = count * 2;
					temp[count] = tree[i]->data;
				}
				else
				{
					current = current->left;
					count = count * 2;
				}
				break;
			case 1:
				if (current->right == NULL)
				{
					current->right = tree[i];
					flag = 0;
					count = count * 2 + 1;
					temp[count] = tree[i]->data;
				}
				else
				{
					current = current->right;
					count = (count * 2) + 1;
				}
				break;
			default:
				break;
			}
		}
	}
	Display(temp);
	printf("\n\n");
	printf("전위 순회");
	Preorder(root);
	printf("\n");
	printf("중위 순회");
	Inorder(root);
	printf("\n");
	printf("후위 순회");
	Postorder(root);
}