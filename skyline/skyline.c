#include <stdio.h>
#pragma warning(disable:4996)
#define MAX 500

struct Build
{
	int x;
	int y;
	int start;
} building[MAX * 2];

struct queue {
	int value;
}Queue[MAX];
void SkyLine()
{
	int previous_max_value = 0;

	int i = 1;
	for (i ; i < MAX * 2; i++)
	{
		if (building[i].x == 0 && building[i].y == 0 && building[i].start == 0) break;
		if (building[i].start == 1)
		{
			Queue[building[i].y].value++;
		}
		else
		{
			Queue[building[i].y].value--;
		}

		//get bigger value from the queue
		int max = 0;
		for (int j = 0; j < MAX; j++)
		{
			if (Queue[j].value != 0)
			{
				max = j;
			}
		}

		int current_max_value = max;

		if (previous_max_value != current_max_value)
		{
			printf("%d %d ", building[i].x, current_max_value);
			previous_max_value = current_max_value;
		}
	}
}
void Rearange()
{
	for (int i = 0; i < MAX * 2; i++)
	{
		if (building[i].x == 0 && building[i].y == 0 && building[i].start == 0) break;
		for (int j = i + 1; j < MAX * 2; j++)
		{
			int aux1 = 0, aux2 = 0, aux3 = 0;
			if (building[j].x == 0 && building[j].y == 0 && building[j].start == 0) break;
			if (building[i].x > building[j].x)
			{
				aux1 = building[j].x;
				aux2 = building[j].y;
				aux3 = building[j].start;
				building[j].x = building[i].x;
				building[j].y = building[i].y;
				building[j].start = building[i].start;
				building[i].x = aux1;
				building[i].y = aux2;
				building[i].start = aux3;
			}
			else if (building[i].x == building[j].x)
			{
				if (building[i].start < building[j].start)
				{
					aux1 = building[j].x;
					aux2 = building[j].y;
					aux3 = building[j].start;
					building[j].x = building[i].x;
					building[j].y = building[i].y;
					building[j].start = building[i].start;
					building[i].x = aux1;
					building[i].y = aux2;
					building[i].start = aux3;
				}
			}
		}
	}
}
int main()
{
	int count = 0;
	int newBdCount = 0;
	do
	{
		scanf("%d", &building[count].x);
		scanf("%d", &building[count].y);
		building[count].start = 1;
		scanf("%d", &building[count + 1].x);
		building[count + 1].start = 0;
		building[count + 1].y = building[count].y;
		count+=2;
	} while (getchar() != '\?');

	Rearange();
	
	SkyLine();

	return 0;
}
/*
Difficulty:Hard
Total Accepted:43.7K
Total Submissions:161K
Companies Microsoft Google Facebook Twitter Yelp
Related Topics Binary Indexed Tree Segment Tree Heap Divide and Conquer
*/