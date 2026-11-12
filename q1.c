// functiions:
//print the lpackages and ask which one needed

// ask mobile number



#include <stdio.h>

int main(void)
{
	// prototypes:
	int packages();
	long long phone();
	void printSlip(long long number, float amount, float tax, float balance);

	float amount;
	float bonus = 0;
	float tax;
	float balance;
	
	int pack = packages();
	long long phone_num = phone(); 
	
	switch (pack)
	{
		case 1:
			amount = 100;
			break;
		case 2: 
			amount = 200;
			break;
		case 3:
			amount = 500;
			break;
		case 4:
			amount = 1000;
			break;
		default:
			amount = 0;
			printf("\n----- invalid package entered -----\n");
	}
	
	if (amount >= 500)
	{
		bonus = 0.1 * amount;
	}
	
	balance = amount + bonus;
	
	tax = 0.15 * amount;
	amount = amount + tax;
	printSlip(phone_num, amount, tax, balance);
}



int packages()
{
	int package;
	
	printf("\n----- Available Packages -----\n");
	printf("1. Rs 100\n");
	printf("2. Rs 200\n");
	printf("3. Rs 500\n");
	printf("4. Rs 1000\n");
	printf("\nSelect package from 1-4: ");
	scanf("%d", &package);
	
	return package;
	

}

long long phone()
{
	long long number;
	printf("input the 11-digit phone number (only numbers, e.g. 03012345678): ");
	scanf("%lld", &number);
	printf("%lld", number);
	
	return number;
}

void printSlip(long long number, float amount, float tax, float balance)
{
	printf("\n\n----- Recharge Slip -----\n\n");
	printf("%-15s | ", "Phone number");
	printf("%lld", number);
	printf("\n-------------------------------------------------\n");
	
	printf("%-15s | ", "Total Amount");
	printf("%0.2f", amount);
	printf("\n-------------------------------------------------\n");

	printf("%-15s | ", "Tax");
	printf("%0.2f", tax);
	printf("\n-------------------------------------------------\n");

	printf("%-15s | ", "Balance added");
	printf("%0.2f", balance);
	printf("\n-------------------------------------------------\n");
}
