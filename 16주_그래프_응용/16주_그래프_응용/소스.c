#include <stdio.h>
#define No_Nodes 7
#define MAX 1000
int weight[No_Nodes][No_Nodes] =
{
	{0,5,6,10,MAX,MAX,MAX},
	{5,0,MAX,7,8,MAX,MAX},
	{6,MAX,0,8,MAX,7,MAX},
	{10,7,8,0,9,6,10},
	{MAX,8,MAX,9,0,MAX,12},
	{MAX,MAX,7,6,MAX,0,9},
	{MAX,MAX,MAX,10,12,9,0}
};
int distance[No_Nodes];
int found[No_Nodes];

void main()
{
	int min = 0;
	int s, e, v;
	printf("출발지점과 도착지점을 입력 : ");
	scanf_s("%d %d", &s, &e);

	for (int i = 0; i < No_Nodes; i++)
	{
		found[i] = 0;
		distance[i] = MAX;
	}
	distance[s] = 0;
	for (int i = 0; i < No_Nodes; i++)
	{
		min = MAX;
		for (int j = 0; j < No_Nodes; j++)
		{
			if (found[j] == 0 && distance[j] < min)
			{
				v = j;
				min = distance[j];
			}
		}
		found[v] = 1;
		for (int j = 0; j < No_Nodes; j++)
		{
			if (distance[j] > distance[v] + weight[v][j])
			{
				distance[j] = distance[v] + weight[v][j];
			}
		}
		printf("S : ");
		for (int i = 0; i < No_Nodes; i++)
		{
			printf("%3d ", found[i]);
		}
		printf("\n");
		printf("distance : ");
		for (int i = 0; i < No_Nodes; i++)
		{
			if (distance[i] == MAX)
				printf("INF | ");
			else
				printf("%3d | ", distance[i]);
		}
		printf("\n\n");
	}
	printf("출발 : %d 도착 : %d\n 최단경로 : %d", s, e, distance[e]);
}