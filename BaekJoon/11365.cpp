#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	char string[10000];
	
	for (i = 0; i < 5; i++)
	{
		int j;
		scanf("%[^\n]s", string);
		
		if (strcmp(string,"END") == 0)
		{
			return 0;
		}

		for (j = strlen(string) - 1; j >= 0; j--)
		{
			printf("%c", string[j]);
		}
		printf("\n");
		getchar();

	}
	
	return 0;
}
