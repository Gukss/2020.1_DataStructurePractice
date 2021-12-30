#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _Node
{
	int key;
	struct Node* Lnode;
	struct Node* Rnode;
}Node;

typedef struct _Tree
{
	Node* root;
}Tree;

void Init(Tree* tree)
{
	tree->root = NULL;
}
//parent 위치 결정
int Search(Tree* tree, int data, Tree** parent)
{
	Node* current = tree->root;

	while (1)
	{
		if ((current->key) == data)
		{
			return 1;
		}
		if (current->key < data)
		{
			*parent = current;
			if (current->Rnode == NULL)
			{
				return 0;
			}
			current = current->Rnode;
		}
		if (current->key > data)
		{
			*parent = current;
			if (current->Lnode == NULL)
			{
				return 0;
			}
			current = current->Lnode;
		}
	}
}

void Insert(Tree* tree, int data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->key = data;
	newnode->Lnode = NULL;
	newnode->Rnode = NULL;
	if (tree->root == NULL)
	{
		tree->root = newnode;
		return;
	}
	Node* parent = NULL;

	if (Search(tree, data, &parent))
	{
		return;
	}
	else
	{
		if (parent->key < data)
		{
			parent->Rnode = newnode;
		}
		else
		{
			parent->Lnode = newnode;
		}
	}
}
//중위 탐색 = 오름차순
void Display(Node* root)
{
	if (root != NULL)
	{
		Display(root->Lnode);
		printf("%d ->", root->key);
		Display(root->Rnode);
	}
}

int Delete(Tree* tree, int data)
{
	Node* current = tree->root;
	Node* Tempcurrent = NULL;
	Node* parent = NULL;
	Node* child = NULL;
	Node* temp = NULL;

	int key = 0;

	if (!Search(tree, data, &temp))
	{
		return;
	}

	while (current->key != data)
	{
		parent = current;
		if (current->key < data)
		{
			current = current->Rnode;
		}
		else
		{
			current = current->Lnode;
		}
	}
	//자식이 없는 경우
	if ((current->Lnode == NULL) && (current->Rnode == NULL))
	{
		key = current->key;

		if (parent->Lnode == current)
		{
			parent->Lnode = NULL;
		}
		else if (parent->Rnode == current)
		{
			parent->Rnode = NULL;
		}
		free(current);
		return key;
	}
	//자식이 하나 있는 경우
	if ((current->Lnode == NULL) || (current->Rnode == NULL))
	{
		key = current->key;
		//자식노드 찾기
		if (current->Lnode != NULL)
		{
			child = current->Lnode;
		}
		else if (current->Rnode != NULL)
		{
			child = current->Rnode;
		}
		//부모와 자식노드의 연결
		if (parent->Lnode == current)
		{
			parent->Lnode = child;
		}
		else
		{
			parent->Rnode = child;
		}
		free(current);
		return key;
	}
	//자식이 둘있는 경우
	//오른 서브트리의 가장 왼쪽값 찾았다.
	if ((current->Lnode != NULL) && (current->Rnode != NULL))
	{
		Tempcurrent = current->Rnode;
		while (Tempcurrent->Lnode != NULL)
		{
			parent = Tempcurrent;
			Tempcurrent = Tempcurrent->Lnode;
		}
		parent->Lnode = NULL;
		current->key = Tempcurrent->key;
		free(Tempcurrent);
	}

}

void main()
{
	Tree tree;
	Init(&tree);

	Insert(&tree, 5);
	Insert(&tree, 6);
	Insert(&tree, 7);
	Insert(&tree, 4);
	Insert(&tree, 8);
	Delete(&tree, 4);
	Insert(&tree, 2);
	Insert(&tree, 13);
	Insert(&tree, 9);
	Delete(&tree, 6);

	Display(tree.root);
}