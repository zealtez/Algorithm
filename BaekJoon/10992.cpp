#include <stdio.h>

int main(void)
{
	int i, j;
	int N;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		for (j = N-1; j > i; j--) //빈칸 그리기
		{
			printf(" ");
		}
		printf("*");// 그리고 한칸 찍기
		
		if (i >= 1) 
		{
			if (i == N - 1)
			{
				for (j = 0; j <= 2 * i - 1; j++)
				{
					printf("*");
				}
				printf("\n");
				return 0;
			}

			for (j = 1; j <= 2 * i - 1; j++)
			{
				printf(" ");
			}
			printf("*");// 그리고 한칸 찍기
		}
		printf("\n");
	}return 0;
}
