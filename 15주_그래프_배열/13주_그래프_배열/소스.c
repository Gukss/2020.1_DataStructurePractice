#include <stdio.h>

#define VERTEX 7

#define Q_SIZE 10

int queue[Q_SIZE];
int front = 0, rear = 0;

void Enqueue(int item)
{
	if (rear + 1 % Q_SIZE == front)
	{
		printf("큐가 포화상태입니다.\n");
		return;
	}
	rear = (rear + 1) % Q_SIZE;
	queue[rear] = item;
}

int Dequeue()
{
	if (front == rear)
	{
		printf("큐가 비었습니다.\n");
		return;
	}
	front = (front + 1) % Q_SIZE;
	return queue[front];
}

void Insert_edge(int mat[VERTEX][VERTEX], int start, int end)
{
	mat[start][end] = 1;
	mat[end][start] = 1;
}

void Dfs_mat(int mat[VERTEX][VERTEX], int V, int dfs_visited[VERTEX])
{
	dfs_visited[V] = 1;
	printf("%3d -> ", V);
	for (int i = 0; i < VERTEX; i++)
	{
		if ((mat[V][i] == 1) && (dfs_visited[i] == 0))
		{
			Dfs_mat(mat, i, dfs_visited);
		}
	}
}

void Bfs_mat(int mat[VERTEX][VERTEX], int V, int bfs_visited[VERTEX])
{
	bfs_visited[V] = 1;
	printf("%3d ->", V);
	Enqueue(V);
	while (front != rear)
	{
		V = Dequeue();
		for (int i = 0; i < VERTEX; i++)
		{
			if ((mat[V][i] == 1) && (bfs_visited[i] == 0))
			{
				Enqueue(i);
				bfs_visited[i] = 1;
				printf("%3d -> ", i);
			}
		}
	}
}
void main()
{
	int mat[VERTEX][VERTEX] = { 0 };
	int dfs_visited[VERTEX] = { 0 }, bfs_visited[VERTEX] = { 0 };
	Insert_edge(mat, 0, 1);
	Insert_edge(mat, 0, 2);
	Insert_edge(mat, 1, 3);
	Insert_edge(mat, 1, 4);
	Insert_edge(mat, 2, 3);
	Insert_edge(mat, 2, 5);
	Insert_edge(mat, 3, 4);
	Insert_edge(mat, 3, 5);
	Insert_edge(mat, 4, 6);
	Insert_edge(mat, 5, 6);

	Dfs_mat(mat, 0, dfs_visited);
	printf("\n");
	Bfs_mat(mat, 0, bfs_visited);
}