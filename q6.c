// NOTE: MEMORY ALLOCATION / FREEING HAS NOT BEEN TAUGHT YET (DATE TODAY: 09-NOV-2026)






#include <stdio.h>

int main(void)
{
	int n; 
	float *high_ptr = NULL;
	float *low_ptr = NULL;
	int high_index = 0;
	int low_index = 0;
	int hot_count = 0;
	int i;
	float *ptr = NULL;
	
	do
	{
		printf("Input number of days of temperature to store (1-10): ");
		scanf("%d", &n);
	}
	while (n > 10 || n < 1);
	
	float temperatures[n];
	
	printf("\n");
	for (i = 0; i < n; i++)
	{
		do
		{
			printf("input the temperature for day %d (-10 to 55 acceptable only): ", i + 1);
			scanf("%f", &temperatures[i]);
		}
		while (temperatures[i] > 55 || temperatures[i] < -10);
	}
	
	printf("\n\n----- temperatures -----\n\n");
	
	high_ptr = temperatures;
	low_ptr = temperatures;
	ptr = temperatures;
	
	for (i = 0; i < n; i++)
	{
		printf("Day %d: %5.1f at address %p\n", i + 1, *(temperatures + i), &temperatures[i]);
	

		if (*ptr > *high_ptr)
		{
			high_ptr = ptr;
			high_index = i;
		}
		
		if (*ptr < *low_ptr)
		{
			low_ptr = ptr;
			low_index = i;
		}
		
		if (*ptr > 40)
		{
			hot_count++;
		}
		ptr++;
	}
	
	
	printf("\n\nHotest Day: Day %d", high_index + 1);
	printf("\nColdest Day: Day %d", low_index + 1);
	printf("\nNumber of days hotter than 40: %d", hot_count);
}


