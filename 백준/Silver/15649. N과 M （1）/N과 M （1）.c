#include <stdio.h>
#include <math.h>
#include <string.h>

int n, m;
int res[1001];
int arr[1001];

void DFS(int depth)
{

	if (depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (arr[i] == 0)
			{
				res[depth] = i;
				arr[i] = 1;
				DFS(depth + 1);
				arr[i] = 0;
			}
		}
	}

}

int main()
{
	scanf("%d %d", &n, &m);
	DFS(0);
	return 0;
}