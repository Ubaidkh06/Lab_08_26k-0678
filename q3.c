	#include <stdio.h>
	
	int main(void)
	{
		// prototypes
		int route_select();
		int seats_select();
		char type_select();
		void print_slip(int route, int seats, char type, float total);
	
		// variables
		int route;
		int seats;
		float rate;
		float total;
		char type;
		
		
		route = route_select();
		seats = seats_select();
		type = type_select();
	
		switch (route)
		{
			case 1:
				rate = 800;
				break;
						
			case 2:
				rate = 2200;
				break;
		
			case 3:
				rate = 3500;
				break;
				
			default:
				printf("incorrect route entered.\n");
				return 1;
		}
		
		total = seats * rate;
		if (type == 'b' || type == 'B')
		{
			total *= 1.3;
		}
	
		print_slip(route, seats, type, total);
	
	
	
		return 0;
	}
	
	
	
	
	int route_select(void)
	{
		int route;
		
		printf("\n\n----- Route Selection -----\n\n");
		
		printf("%-25s | ", "ROUTES");
		printf("%s", "COST");
		printf("\n-------------------------------------------------\n");
		printf("%-25s | Rs. 800\n", "1. Karachi to Hyderabad");
		printf("%-25s | Rs. 2200\n", "2. Karachi to Sukkur");
		printf("%-25s | Rs. 3500\n", "3. Karachi to Multan");
	
		do
		{
			printf("\nSelect a route (1 to 3): ");
			scanf("%d", &route);
		}
		while (route > 3 || route < 1);
		return route;
	}
	
	
	int seats_select()
	{
		int seats;
		
		printf("\n\n----- Seats selection -----\n\n");
		
		do
		{
			printf("input number of seats (1 to 6): ");
			scanf("%d", &seats);
		}
		while (seats > 6 || seats < 1);
		
		return seats;
	}
	
	
	char type_select()
	{
		char type;
		printf("\n\n----- Type selection -----\n\n");
		
		do
		{
			printf("input the seats type ('E' for Economy, 'B' for Business): ");
			scanf(" %c", &type);
		}
		while (type != 'e' && type != 'E' && type != 'B' && type != 'b');
		
		return type;
	}
	
	void print_slip(int route, int seats, char type, float total)
	{
			printf("\n\n -----%f----- \n\n", total);
	
		printf("\n\n----- Bus tickets slip -----\n\n");
		
		printf("%s | ", "route");
		switch (route)
		{
			case 1:
				printf("Karachi to Hyderabad");
				break;
				
			case 2:
				printf("Karachi to Sukkur");
				break;
				
			case 3:
				printf("Karachi to Multan");
				break;
		}
		printf("\n--------------------------------\n");
		
		printf("%-5s | %d", "seats", seats);
		printf("\n--------------------------------\n");
		
		printf("%-5s | ", "type");
		
		switch(type)
		{
			case 'e':
			case 'E':
				printf("Economy");
				break;
			
			case 'b':
			case 'B':
				printf("Business");
				break;
		}
		printf("\n--------------------------------\n");
	
		printf("%-5s | %0.2f", "total", total);
		
	}


// 	printf("\n\n -----%d----- \n\n", route);

