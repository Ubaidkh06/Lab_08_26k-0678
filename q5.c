#include <stdio.h>

int main(void)
{
	// prototypes
	void sales(double *p_costPrice, double *p_sellPrice, double *p_quantity, double *p_profit_percent,  double *greater);
	
	// variables
	double costPrice, sellPrice, quantity, profit_percent;
	double *p_costPrice = &costPrice;
	double *p_sellPrice = &sellPrice;
	double *p_quantity = &quantity;
	double *p_profit_percent = &profit_percent;
	double *greater = NULL;

	
	sales(p_costPrice, p_sellPrice, p_quantity, p_profit_percent, greater);
	
	if (costPrice > sellPrice)
	{
		greater = p_costPrice;
	}
	else if (sellPrice > costPrice)
	{
		greater = p_sellPrice;
	}
	
	printf("\n\n----- Pointers -----\n");
	printf("1. %-20s | %p\n", "cost price", p_costPrice);
	printf("2. %-20s | %p\n", "sell price", p_sellPrice);	
	printf("3. %-20s | %p\n", "quantity", p_quantity);
	printf("4. %-20s | %p\n", "profit percentage", p_profit_percent);
	printf("5. %-20s | %p\n", "greater price", greater);
	
	printf("\n----- Values -----\n");
	printf("1. %-20s | %0.2lf\n", "cost price", *p_costPrice);
	printf("2. %-20s | %0.2lf\n", "sell price", *p_sellPrice);	
	printf("3. %-20s | %.0lf\n", "quantity", *p_quantity);
	printf("4. %-20s | %0.1lf%%\n", "profit percentage", *p_profit_percent);
	printf("5. %-20s | ", "greater price");
	if (greater == NULL)
	{
		printf("N/A\n");
	}
	else
	{
		printf("%0.2lf\n", *greater);
	}

}


void sales(double *p_costPrice, double *p_sellPrice, double *p_quantity, double *p_profit_percent,  double *greater)
{
	float cp, sp, quantity;
	
	do
	{
		printf("Input cost price of the product: ");
		scanf("%f", &cp);
	}
	while (cp < 0);
	
	do
	{
		printf("Input selling price of the product: ");
		scanf("%f", &sp);
	}
	while (sp < 0);
	
	do
	{
		printf("Input quantity sold of the product: ");
		scanf("%f", &quantity);
	}
	while (quantity < 0);
	
	*p_costPrice = cp;
	*p_sellPrice = sp;
	*p_quantity = quantity;
	
	if (*p_costPrice > *p_sellPrice)
	{
		printf("\nLoss");
		greater = p_costPrice;
	}
	else if (*p_sellPrice > *p_costPrice)
	{
		printf("\nProfit");
		greater = p_sellPrice;
	}
	else
	{
		printf("\nNo profit no loss");
	}
	
	*p_profit_percent = ((*p_sellPrice - *p_costPrice) /  *p_costPrice) * 100;
}


