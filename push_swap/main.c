#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *array;
	int i;

	i = 0;
	array = malloc(sizeof(int) * 1);

	array[0] = 1;
	if (!array[1])
		printf("yes\n");
	printf("no\n");
}
