#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

void Print(int arr[])
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

void Swap(int arr[], int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void Bubble_sort(int arr[])
{
	int i = 0, j = 0;
	for (i = MAX_SIZE - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(arr, j, j + 1);
			}
		}
		Print(arr);
	}
}

void Insert_sort(int arr[])
{
	int i, j, next;
	for (i = 1; i < MAX_SIZE; i++)
	{
		next = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > next; j--)
		{
			arr[j + 1] = arr[j];
		}
		//반복문 j연산 때문에
		arr[j + 1] = next;
		Print(arr);
	}
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left+1;
	int high = right;

	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
		{
			low++;
		}
		while (pivot <= arr[high] && high >= (left + 1))
		{
			high--;
		}
		if (low <= high)
		{
			Swap(arr,low, high);
		}
	}
	Swap(arr, left, high);
	return high;
}

void Quick_sort(int arr, int left, int right)
{
	if (left < right)
	{
		int q = Partition(arr, left, right);
		Print(arr);
		Quick_sort(arr, left, q - 1);
		Quick_sort(arr, q + 1, right);
	}
}

void main()
{
	int b_ar[MAX_SIZE], i_ar[MAX_SIZE], q_ar[MAX_SIZE];

	srand((unsigned)time(NULL));

	for (int i = 0; i < MAX_SIZE; i++)
	{
		b_ar[i] = rand() % 10 + 1;
		i_ar[i] = b_ar[i];
		q_ar[i] = b_ar[i];
		for (int j = 0; j < i; j++)
		{
			if (b_ar[j] == b_ar[i])
			{
				i--;
				break;
			}
		}
	}

	Print(b_ar);
	printf("-----버블정렬-----\n");
	Bubble_sort(b_ar);
	printf("-----삽입정렬-----\n");
	Insert_sort(i_ar);
	printf("-----퀵정렬-----\n");
	Quick_sort(q_ar, 0, MAX_SIZE - 1);
}