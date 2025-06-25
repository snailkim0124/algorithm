#include <stdio.h>
#include <math.h>

int main()
{
	int n, m;
	char board[51][51] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", board[i]);
	}

	int min = 100000;
	int white = 0;
	int black = 0;
	for (int i = 0; i < n-7; i++)
	{
		for (int j = 0; j < m-7; j++)
		{
			white = 0;
			black = 0;
			for (int k = i; k < i +8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if ((k + l) % 2 == 0)
					{
						if (board[k][l] == 'B')
						{
							white++;
						}
						else
						{
							black++;
						}
					}
					else
					{
						if (board[k][l] == 'B')
						{
							black++;
						}
						else
						{
							white++;
						}
					}
				}
			}
			if (min > black)
			{
				min = black;
			}
			if (min > white)
			{
				min = white;
			}
		}
	}
	printf("%d", min);
	return 0;
}