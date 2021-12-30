#include <stdio.h>
#include <malloc.h>

#define VERTEX 7

typedef struct _G_node
{
	int vertex;
	struct G_node* link;
}G_node;

void Insert_edge(G_node* list[VERTEX], int start, int end)
{
	G_node* node = (G_node*)malloc(sizeof(G_node));
	node->vertex = end;
	node->link = list[start];
	list[start] = node;
}

void Creat_adj_list(G_node* list[VERTEX], int mat[VERTEX][VERTEX])
{
	for (int i = 0; i < VERTEX; i++)
	{
		for (int j = 0; j < VERTEX; j++)
		{
			if (mat[i][j] == 1)
			{
				Insert_edge(list, i, j);
			}
		}
	}
}

void Dfs_mat(G_node* list[VERTEX], int V, int dfs_visited[VERTEX])
{
	G_node* w;
	dfs_visited[V] = 1;
	printf("%3d -> ", V);
	for (w = list[V]; w; w = w->link)
	{
		if (!dfs_visited[w->vertex])
		{
			Dfs_mat(list, w->vertex, dfs_visited);
		}
	}
}

void Creat_mat(int mat[VERTEX][VERTEX], int start, int end)
{
	mat[start][end] = 1;
	mat[end][start] = 1;
}

void main()
{
	G_node *List[VERTEX] = {'\0'};
	int mat[VERTEX][VERTEX] = { 0 };
	int dfs_visited[VERTEX] = { 0 };
	Creat_mat(mat, 0, 1);
	Creat_mat(mat, 0, 2);
	Creat_mat(mat, 1, 3);
	Creat_mat(mat, 1, 4);
	Creat_mat(mat, 2, 3);
	Creat_mat(mat, 2, 5);
	Creat_mat(mat, 3, 4);
	Creat_mat(mat, 3, 5);
	Creat_mat(mat, 4, 6);
	Creat_mat(mat, 5, 6);

	Creat_adj_list(List, mat);

	Dfs_mat(List, 0, dfs_visited);
}