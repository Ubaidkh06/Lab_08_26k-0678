#include <stdio.h>

int main(void)
{
	// prototypes
	int findMax(int *p, int n);
	int findMin(int *p, int n);
	double findAverage(int *p, int n);
	int countAbove(int *p, int n, double avg);
	void reverseArray(int *p, int n);
	void printArray(int *p, int n);
	int passCount(int *p, int n);


	
	// variables
	int marks[10];
	int len = sizeof(marks) / sizeof(marks[0]);	
	int i;
	int high_marks;
	int lowest_marks;
	double avg;
	int above_average;
	int key;
	int key_position;
	int pass_count;
	
	for (i = 0; i < len; i++)
	{
		do
		{
			printf("Input marks of student %d: ", i + 1);
			scanf("%d", &marks[i]);
		}
		while(marks[i] > 100 || marks[i] < 0);	
	}
	
	printf("\n\ninput marks to find their position in the reversed array: ");
	scanf("%d", &key);
	
	printf("\nMarks before reversing: ");
	printArray(marks, len);

	
	high_marks = findMax(marks, len);
	lowest_marks = findMin(marks, len);
	avg = findAverage(marks, len);
	above_average = countAbove(marks, len, avg);
	
	reverseArray(marks , len);
	printf("\nMarks After reversing:  ");
	printArray(marks, len);
	
	key_position = searchMark(marks, len, key);
	
	if (key_position == -1)
	{
		printf("\nMarks NOT found\n");
	}
	else
	{
		printf("\nMarks were found at position: %d\n", key_position);
	}
	
	printf("\nMax marks: %d\n", high_marks);
	printf("Min marks: %d\n", lowest_marks);
		

	
	pass_count = passCount(marks, len);
	printf("\nNumber of Students passed: %d", pass_count);
}



int findMax(int *p, int n) // p points at the first element of the array
{
	int *high_p = p;
	int i;
	
	for (i = 0; i < n; i++)
	{
		if (*p > *high_p)
		{
			high_p = p;
		}
		p++;
	}
	return *high_p;
}


int findMin(int *p, int n)
{
	int *low_p = p;
	int i;
	
	for (i = 0; i < n; i++)
	{
		if (*p < *low_p)
		{
			low_p = p;
		}
		p++;
	}
	return *low_p;
}

double findAverage(int *p, int n)
{
	float sum = 0;
	int i;
	
	for (i = 0; i < n; i++)
	{
		sum += *p;
		p++;
	}

	return sum / n;
}


int countAbove(int *p, int n, double avg)
{
	int count = 0;
	int i;
	
	for (i = 0; i < n; i++)
	{
		if (*p > avg)
		{
			count++;
		}
		p++;
	}
	
	return count;
}




void reverseArray(int *p, int n)
{
	int temp;
	int *last_p = p + n - 1;
	
	while (last_p > p && last_p != p)
	{
		temp = *p;
		*p = *last_p;
		*last_p = temp;
		
		p++;
		last_p--;
	}
	
	
}



int searchMark(int *p, int n, int key)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		if (*p == key)
		{
			return i + 1;	
		}	
		p++;
	}
	return -1;
}



void printArray(int *p, int n)
{
	int i;
	
	for (i = 0; i < n; i++)
	{
		printf("%d ", *p);
		p++;
	}
}

int passCount(int *p, int n)
{
	int count = 0;
	int i;
	
	for (i = 0; i < n; i++)
	{
		if (*p >= 40)
		{
			count++;
		}
		p++;
	}
	return count;
}
// 	printf("\n\n----- %d ------\n\n", len);

