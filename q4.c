#include <stdio.h>

int main(void)
{
	// prototypes
	int select_km(void);
	int select_wait(void);
	float calc_km_charge(int km);
	float calc_wait_charge(int wait);
	void print_receipt(int km, int wait, float fare);
	
	// variables
	int km;
	int wait;
	float km_charge;
	float wait_charge;
	int hour;
	int fare;
	
	// code
	km = select_km();
	wait = select_wait();
	
	km_charge = calc_km_charge(km);
	wait_charge = calc_wait_charge(wait);		
	fare = km_charge + wait_charge;
	
	do
	{
		printf("Input hour of the trip (0-23): ");
		scanf("%d", &hour);
	}
	while (hour < 0 || hour > 23);
	
	if (hour >= 22 || hour < 6)
	{
		fare *= 1.25;
	}	
	
	print_receipt(km, wait, fare);
}




















int select_km(void)
{
	int km;
	
	printf("\n\n----- FARE RULES -----\n\n");
	printf("%-20s | Rs. 150", "Base fare");
	printf("\n------------------------------------\n");
	
	printf("%-20s | Rs. 60/km", "first 10 km");
	printf("\n------------------------------------\n");
	
	printf("%-20s | Rs. 45/km", "After first 10 km");
	printf("\n------------------------------------\n");
	
	do
	{
		printf("\nInput number of km (1-200): ");
		scanf("%d", &km);
	}
	while(km < 1 || km > 200);
	
	return km;
}


int select_wait(void)
{
	int wait;
	
	do
	{
		printf("\nInput waiting time in minutes (0-120): ");
		scanf("%d", &wait);
	}
	while (wait > 120 || wait < 0);
	
	return wait;
}





float calc_km_charge(int km)
{
	float fare = 150;
	if (km <= 10)
	{
		fare += (km * 60);
	}
	else
	{
		fare += 600 + (45 * (km - 10));
	}

	
	return fare;
}




float calc_wait_charge(int wait)
{
	float fare = 0;
	
	if (wait > 5)
	{
		fare += ((wait - 5) * 10);
	}
	
	return fare;
}

void print_receipt(int km, int wait, float fare)
{
	printf("\n\n----- RECEIPT -----\n\n");
	
	printf("%-15s | %d", "Distance", km);
	printf("\n-----------------------------------\n");
	
	printf("%-15s | %d", "Waiting time", wait);
	printf("\n-----------------------------------\n");
	
	printf("%-15s | %0.2f", "Total fare", fare);
	printf("\n-----------------------------------\n");
	
	
}


// printf("\n\n----- %d -----\n\n", km);

