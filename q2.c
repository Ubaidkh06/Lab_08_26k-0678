#include <stdio.h>

int main(void)
{
	// prototypes
	int room_select();
	int days_select();
	float medicine_charge();
	void print_bill(int type, int days, float room_charges, float meds_charges, float total_cost, int flag);

	
	// variables
	int type;
	int days;	
	int room_rate;
	float meds_charge;
	float room_charge;
	float total_cost;
	int flag = 0;
	
	type = room_select();
	days = days_select();
	
	switch (type)
	{
		case 1: 
			room_rate = 1500;
			break;
		
		case 2:
			room_rate = 3500;
			break;
			
		case 3:
			room_rate = 6000;
			break;
		
		default:
			printf("Error: Wrong room entered (must be between 1 and 3 inclusive)\n");
			return 1; 
	}
	
	room_charge = days * room_rate;
	meds_charge = 1.05 * medicine_charge();
	total_cost = room_charge + meds_charge;
	
	if (days >= 7)
	{
		total_cost *= 0.92;
		flag = 1;
	}
	
	print_bill(type, days, room_charge, meds_charge, total_cost, flag);
	
	return 0;
}


int room_select()
{
	int type;
	
	printf("\n----- FAST Hospital-----\n");
	
	printf("\n1. %-15s | ", "General Ward");
	printf("Rs. 1500/day ");
	printf("\n--------------------------------\n");
	
	printf("\n2. %-15s | ", "Semi-Private");
	printf("Rs. 3500/day ");
	printf("\n--------------------------------\n");
	
	printf("\n3. %-15s | ", "Private");
	printf("Rs. 6000/day ");
	printf("\n--------------------------------\n");
	
	do
	{
		printf("\n Select the room type (1 to 3): ");
		scanf("%d", &type);
	}
	while (type < 1 || type > 3);
	return type;
}


int days_select()
{
	int days;
	do
	{
		printf("\nInput number of days stayed (1-30): ");
		scanf("%d", &days);
	}
	while (days < 1 || days > 30);
	return days;
}

float medicine_charge()
{
	float cost;
	
	do
	{
		printf("\nInput cost of the medicine: ");
		scanf("%f", &cost);
	}
	while (cost < 1);
	return cost;
}



void print_bill(int type, int days, float room_charges, float meds_charges, float total_cost, int flag)
{
	printf("\n\n----- Hospital Bill -----\n\n");
	printf("%-25s | ", "Room type");
	
	switch (type)
	{
		case 1: 
			printf("General Ward");
			break;
		
		case 2:
			printf("Semi-Private");
			break;
		case 3:
			printf("Private");
			break;
	}

	printf("\n------------------------------------------------------------\n");

	printf("%-25s | ", "Days Stayed");	
	printf("%d", days);
	printf("\n------------------------------------------------------------\n");
	
	printf("%-25s | ", "Room charges (total)");	
	printf("%0.2f", room_charges);
	printf("\n------------------------------------------------------------\n");
		
	printf("%-25s | ", "Medicine charges (total)");	
	printf("%0.2f", meds_charges);
	printf("\n------------------------------------------------------------\n");
	
		
	printf("%-25s | ", "total grand final cost");	
	printf("%0.2f", total_cost);
	if (flag == 1)
	{
		printf(" (8%% discount applied)");
	}
	printf("\n------------------------------------------------------------\n");
	
	
	

}
// printf("\n\n===== %d =====\n\n", type);
