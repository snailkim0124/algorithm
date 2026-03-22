#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m, b;
	int arr[501][501] = { 0 };
	int max = 0;
	int max_cnt = 0;
	int min = 256;
	int min_cnt = 0;

	scanf("%d %d %d", &n, &m, &b);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
			if (max < arr[i][j])
			{
				max = arr[i][j];
			}
			if (min > arr[i][j])
			{
				min = arr[i][j];
			}
		}
	}

	int time = 0;
	int min_time = 10000000000;
	int answer = 0;


	for (int i = max; i >= min; i--)
	{
		int inven = b;
		time = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				int diff = arr[j][k] - i;

				if (diff < 0)
				{
					time -= diff;
					inven += diff;
				}
				else if (diff > 0)
				{
					time += diff * 2;
					inven += diff;
				}
			}
		}

		if (inven >= 0)
		{
			if (time < min_time)
			{
				min_time = time;
				answer = i;
			}
		}

	}
	printf("%d %d", min_time, answer);


	return 0;
}