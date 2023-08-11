#include <stdio.h>
#include <math.h>


int factorial(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		return n * factorial(n - 1);
	}


}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", factorial(n)/ (factorial(k)*factorial(n-k)));
}