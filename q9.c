// 5 STUDENTS
// each stdeunt: 3 marks (0 to 100)
// if marks 1 to 5 less than pass -> grace marks


#include <stdio.h>
#include <string.h>

#define STUDENTS 5
#define MARKS 3

	//prototypes (NOTE: prototypes placed outside main cuz other functions are accessing other functions also -> readMarks calls addGraceMarks)
	
	void readMarks(int *m1, int *m2, int *m3, int student);
	void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest);
	void swapMarks(int *m1, int *m2, int *m3);
	void addGraceMarks(int *m1, int *m2, int *m3);
	void findGrade(double avg, char *grade, char *remarks);
	
int main(void)
{


	
	int array[STUDENTS][MARKS];
	int marks1, marks2, marks3;
	int *m1 = &marks1;
	int *m2 = &marks2;
	int *m3 = &marks3;
	
	int total_marks;
	int *total = &total_marks;
	double avg;
	double *average = &avg;
	int high = 0;
	int *highest = &high;
	int low = 100;
	int *lowest = &low;
	char grade;
	char *p_grade = &grade;
	char remarks[20];
	
	
	int i;
	
	for (i = 0; i < STUDENTS; i++)
	{
		readMarks(m1, m2, m3, i);
		array[i][0] = *m1;
		array[i][1] = *m2;
		array[i][2] = *m3;
		
		calculateStats(marks1, marks2, marks3, total, average, highest, lowest);
		swapMarks(m1, m2, m3);
		findGrade(avg, p_grade, remarks);
		
		printf("\n\n----- Student %d -----\n\n", i + 1);
		printf("%-10s | %d", "Total", total_marks);
		printf("\n----------------------------------------------\n");
		printf("%-10s | %0.2lf", "Average", avg);
		printf("\n----------------------------------------------\n");
		printf("%-10s | %c", "Grade", grade);
		printf("\n----------------------------------------------\n");
		printf("%-10s | %s", "Remarks", remarks);
		printf("\n----------------------------------------------\n\n");




		
	}
    return 0;
}


void readMarks(int *m1, int *m2, int *m3, int student)
{
	do
	{
		printf("Input marks for student %d, marks 1: ", student + 1);
		scanf("%d", m1);
	}
	while (*m1 > 100 || *m1 < 0);
	
	do
	{
		printf("Input marks for student %d, marks 2: ", student + 1);
		scanf("%d", m2);
	}
	while (*m2 > 100 || *m2 < 0);
	
	do
	{
		printf("Input marks for student %d, marks 3: ", student + 1);
		scanf("%d", m3);
	}
	while (*m3 > 100 || *m3 < 0);
	
	addGraceMarks(m1, m2, m3);

}

void calculateStats(int m1, int m2, int m3, int *total, double *average, int *highest, int *lowest)
{
	*total = m1 + m2 + m3;
	*average = *total / 3.0;
	
	if (m1 > m2)
	{
		if (m1 > m3)
		{
			*highest = m1;
		}
		else
		{
			*highest = m3;
		}
	}
	else // m2 is greater than m1
	{
		if (m2 > m3)
		{
			*highest = m2;
		}
		else // m3 is greater tahn m2
		{
			*highest = m3;
		}
	}
	
	if (m1 < m2)
	{
		if (m1 < m3)
		{
			*lowest = m1;
		}
		else
		{
			*lowest = m3;
		}
	}
	else // m2 is greater than m1
	{
		if (m2 < m3)
		{
			*lowest = m2;
		}
		else // m3 is greater tahn m2
		{
			*lowest = m3;
		}
	}
}

void swapMarks(int *m1, int *m2, int *m3)
{
	int i;
	int temp;
	
	for (i = 0; i < 2; i++)
	{
		if (*m2 > *m1)
		{
			temp = *m1;
			*m1 = *m2;
			*m2 = temp;
		}
		
		if (*m3 > *m2)
		{
			temp = *m2;
			*m2 = *m3;
			*m3 = temp;
		}
	}
}

void addGraceMarks(int *m1, int *m2, int *m3)
{
	if (*m1 < 40 && *m1 >= 35)
	{
		*m1 = 40;
	}
	
	if (*m2 < 40 && *m2 >= 35)
	{
		*m2 = 40;
	}
	
	if (*m3 < 40 && *m3 >= 35)
	{
		*m3 = 40;
	}
}



void findGrade(double avg, char *grade, char *remarks)
{
	if (avg >= 85)
	{
		*grade = 'A';
		strcpy(remarks, "Excellent");
	}
	else if (avg >= 75)
	{
		*grade = 'B';
		strcpy(remarks, "Excellent");
	}
	else if (avg >= 65)
	{
		*grade = 'C';
		strcpy(remarks, "Good");
	}
	else if (avg >= 55)
	{
		*grade = 'D';
		strcpy(remarks, "Good");
	}
	else if (avg >= 40)
	{
		*grade = 'E';
		strcpy(remarks, "Good");
	}
	else
	{
		*grade = 'F';
		strcpy(remarks, "Need Improvement");

	}
	

}
