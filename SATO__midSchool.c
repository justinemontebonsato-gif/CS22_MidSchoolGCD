#include <stdio.h>

#define FLUSH while(getchar() != '\n')
#define MAXF 32

int get_Prime_Factors(int, int []);
int find_GCD(int [], int, int [], int);
void display_Factors(int, int [], int);

int main(void)
{
	int m, n, gcd, mCount, nCount;
	int mFactors[MAXF], nFactors[MAXF];

	do{
		m = 0;
		n = 0;
		printf("\nEnter m: ");
		scanf("%d", &m);
		FLUSH;
		printf("\nEnter n: ");
		scanf("%d", &n);
		FLUSH;
		if (m <= n || n < 1)
			printf("\nm must be greater than n, and n must be at least 1. Try again...\n");
	}while (m <= n || n < 1);

	mCount = get_Prime_Factors(m, mFactors);
	nCount = get_Prime_Factors(n, nFactors);

	display_Factors(m, mFactors, mCount);
	display_Factors(n, nFactors, nCount);

	gcd = find_GCD(mFactors, mCount, nFactors, nCount);
	printf("\n\nThe GCD of %d and %d is %d", m, n, gcd);
	return 0;
}

int get_Prime_Factors(int num, int factors[])
{
	int divisor = 2, count = 0;

	while (num > 1)
	{
		if (num % divisor == 0)
		{
			factors[count] = divisor;
			count++;
			num = num / divisor;
		}
		else
			divisor++;
	}
	return count;
}

int find_GCD(int mFactors[], int mCount, int nFactors[], int nCount)
{
	int i = 0, j = 0, gcd = 1;

	while (i < mCount && j < nCount)
	{
		if (mFactors[i] == nFactors[j])
		{
			gcd = gcd * mFactors[i];
			i++;
			j++;
		}
		else if (mFactors[i] < nFactors[j])
			i++;
		else
			j++;
	}
	return gcd;
}

void display_Factors(int num, int factors[], int count)
{
	int j;

	printf("\nPrime factors of %d: ", num);
	for (j = 0; j < count; j++)
		printf("%d ", factors[j]);
	return;
}