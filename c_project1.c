#include<stdio.h>

int Lcm_Hcf(int, int, char);
void Triad(int);
void Rpm(int, int);
void Amount(int);
void _form_triads(int);

// PROJECT INCOMPLETE!!!!!

void main(void)
{
	int option, show=0, n1, n2, amount, store;
	char o, ch, ans='y';
	
	
	while(ans=='y' || ans=='Y')
	{
	
		printf("________<Menu>________\n\n");
		
		printf("Choose any one option from the following....\n\n");
		printf("1# Find HCF and LCM of two numbers.\n");
		printf("2# Print triad* numbers.\n");
		printf("3# Multiply two numbers using ^Russian Peasant Method.\n");
		printf("4# Calculate how many 100 rupee notes, 50, 20, 10, 5, 2, or 1 rupee notes will be required for a particular amount.\n");
		printf("5# Typecast a character and check if that character forms triads.\n\n");
		
		if(show==0)
		{
			printf("\n  *  ->  triads are 3 digit numbers written in a row where no digit in repeated on any number.\n\n");
			printf("The second 3 digit number is 2 times the first 3 digit number and the 3rd 3 digit number is 3 times the 1st 3 digit number.\n");
			printf("The digits on one 3 digit number are repeated on the other 3 digit numbers.\n");
			printf("Eg:  ->  219\t438\t657, no digits have been repeated......\n\n");
			printf("\nDigits may repeat on a particular 3 digit number like : 343, but that digit should repeat on the other 3 digit numbrers...\n\n");
			
			printf(" ^ -> Russian Peasant Method:-> basically for multiplication, you can use Russian Peasant Method, here the first number is divided");
			printf(" continuously by 2 until reduces to 1 and \nthe second number is continuously multiplied by 2 until its corresponding first number reduces to 1.\n\n");
			printf("Eg. ->  multiply 19 and 25.....\n\n");
			printf("19\t25\n|\t|\nv\tv\n9\t50\n|\t|\nv\tv\n4\t100\n|\t|\nv\tv\n2\t200\n|\t|\nv\tv\n1\t400\n\n");
			printf("\nAdd those multiples of the second number whose corresponding first numbers are odd numbers....\n\n");
			printf("\nIn the above example we will add 25, 50, 400, because their corresponding first numbers are odd numbers i.e. 19, 9, 1...\n\n");
			show++;
		}
		
		printf(">option< ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
			
			printf("}Choose{ LCM or HCF(*Enter \"l\" or \"L\" for LCM and enter \"h\" or \"H\" for HCF*)>>>>>>");
			scanf(" %c", &o);
			
			if(o=='l' || o=='L')
			{
				printf("Enter first number: ");
				scanf("%d", &n1);
				printf("Enter second number: ");
				scanf("%d", &n2);
				
				Lcm_Hcf(n1, n2, o);
			}
			
			else if(o=='h' || o=='H')
			{
				printf("Enter first number: ");
				scanf("%d", &n1);
				
				printf("Enter second number: ");
				scanf("%d", &n2);
				
				Lcm_Hcf(n1, n2, o);
			}
			
			else
			{
				printf("\n\nINVALID OPTION!!!\n\n");
			}
			break;
			
			case 2:
			printf("Enter a 3 digit number.....");
			scanf("%d", &n1);
			
			if(n1>=100 && n1<=999)
			{
				Triad(n1);
			}
			
			else
			{
				printf("\n%d is not a 3 digit number......\n\n", n1);
			}
			break;
			
			case 3:
			printf("Enter two numbers to multiply(format-> (\"first_numberxsecond_number\"): ");
			scanf("%dx%d", &n1, &n2);
			
			Rpm(n1, n2);
			break;
			
			case 4:
			printf("Enter an amount....");
			scanf("%d", &amount);
			
			Amount(amount);
			
			break;
			
			case 5:
			printf("Enter a character: ");
			scanf(" %c", &ch);
			
			store=(int)ch; // typecasting ch to int
			
			if(store>=100 && store<=999)
			{
				_form_triads(store);
			}
			
			else
			{
				printf("\n%d is not a 3 digit number.....\n\n\n", store);
			}
			
			break;
			
			default:
			
			printf("\n\nINVALID OPTION!!!!!\n\n\n");
		}
		
		printf("Do you want to continue? ");
		scanf(" %c", &ans);
	}
	
	
	
}


int Lcm_Hcf(int n1, int n2, char choice)
{
	int product1, product2, i=1, j=1, limit=10, replica, r1, r2;
	if(choice=='l' || choice=='L')
	{
		while(!0)
		{
			while(i<=limit)
			{
				product1=n1*i;
				while(j<=limit)
				{
					product2=n2*j;
					
					if(product1==product2)
					{
						printf("\n%d is the LCM of %d and %d...\n\n", product1, n1, n2);
						return 0;
					}
					
					j++;
				}
				
				j=1;
				i++;
				
				if(i==limit)
				{
					limit+=10;
					i=1;
				}
			}
		}
		

	}
	
	else if(choice=='h' || choice=='H')
	{
		if(n1>n2)
			replica=n1;
		else
			replica=n2;
		
		while(!0)
		{
			r1=n1%replica;
			r2=n2%replica;
			
			if(r1==0 && r2==0)
			{
				printf("\n%d is the HCF of %d and %d....\n\n", replica, n1, n2);
				return 0;
			}
			
			replica--;
		}
		
	}
	
	return 0;
}


void Triad(int n)
{
	int replica1=n, replica2=n*2, replica3=n*3, last_digit1, last_digit2, last_digit3, is_triad=1;
	
	int i=1;
	while(i<=3)
	{
		printf("%d\t", n*i);
		i++;
	}
	
	if(replica2>999)
	{
		printf("\nTriads cannot be formed....%d is not a 3 digit number...\n\n", replica2);
		return;
	}
	
	if(replica3>999)
	{
		printf("\nTriads cannot be formed....%d is not a 3 digit number...\n\n", replica3);
		
		return;
	}
	
	
	// compare n and n*2
	
	while(replica1!=0)
	{
		last_digit1=replica1%10;
		while(replica2!=0)
		{
			last_digit2=replica2%10;
			if(last_digit1==last_digit2)
			{
				is_triad=0;
				break;
			}
			
			replica2/=10;
		}
		
		if(is_triad==0)
		{
			printf("\nNumbers donot form triads...digits were repeated....\n\n");
			return;
		}
		replica2=n*2;
		
		replica1/=10;
	}
	replica1=n;
	
	// compare n*2 and n*3
	
	
	while(replica2!=0)
	{
		last_digit2=replica2%10;
		
		while(replica3!=0)
		{
			last_digit3=replica3%10;
			if(last_digit2==last_digit3)
			{
				is_triad=0;
				break;
			}
			
			replica3/=10;
		}
		
		if(is_triad==0)
		{
			printf("\nNumbers donot form triads...digits were repeated....\n\n");
			return;
		}
		
		replica3=n*3;
		
		replica2/=10;
	}
	
	replica2=n*2;
	
	// compare n and n*3
	
	while(replica1!=0)
	{
		last_digit1=replica1%10;
		
		while(replica3!=0)
		{
			last_digit3=replica3%10;
			if(last_digit1==last_digit3)
			{
				is_triad=0;
				break;
			}
			
			replica3/=10;
		}
		
		if(is_triad==0)
		{
			printf("\nNumbers donot form triads...digits were repeated....\n\n");
			return;
		}
		
		replica3=n*3;
		replica1/=10;
	}
	
	if(is_triad==1)
	{
		printf("\nThe numbers form triads...\n\n\n");
	}
	
}

void Rpm(int n1, int n2)
{
	int sum=0, replica1=n1, replica2=n2;
	while(replica1>0)
	{
		
		if(replica1%2!=0)
		{
			sum+=replica2;
		}
		
		replica1/=2;
		replica2*=2;
	}
	
	
	
	printf("\n\nThe product of %d and %d is....%d....\n\n", n1, n2, sum);
	
	return;
}

void Amount(int amt)
{
	int num_choice, replica=amt, show, left;
	
	printf("\nEnter the number from which you want to start counting...");
	scanf("%d", &num_choice);
	
	switch(num_choice)
	{
		case 100:
		if(replica>=100)
		{
			show=replica/100;
			left=replica%100;
			printf("\nNumber of 100 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=50)
		{
			show=replica/50;
			left=replica%50;
			printf("\nNumber of 50 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=20)
		{
			show=replica/20;
			left=replica%20;
			printf("\nNumber of 20 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=10)
		{
			show=replica/10;
			left=replica%10;
			printf("\nNumber of 10 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=5)
		{
			show=replica/5;
			left=replica%5;
			printf("\nNumber of 5 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=2)
		{
			show=replica/2;
			left=replica%2;
			printf("\nNumber of 2 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=1)
		{
			show=replica/1;
			left=replica%1;
			printf("\nNumber of 1 rupee note(s) required... %d\n\n", show);
		}
		break;
		
		case 50:
		if(replica>=50)
		{
			show=replica/50;
			left=replica%50;
			printf("\nNumber of 50 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=20)
		{
			show=replica/20;
			left=replica%20;
			printf("\nNumber of 20 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=10)
		{
			show=replica/10;
			left=replica%10;
			printf("\nNumber of 10 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=5)
		{
			show=replica/5;
			left=replica%5;
			printf("\nNumber of 5 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=2)
		{
			show=replica/2;
			left=replica%2;
			printf("\nNumber of 2 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=1)
		{
			show=replica/1;
			left=replica%1;
			printf("\nNumber of 1 rupee note(s) required... %d\n\n", show);
		}
		break;
		
		case 20:
		if(replica>=20)
		{
			show=replica/20;
			left=replica%20;
			printf("\nNumber of 20 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=10)
		{
			show=replica/10;
			left=replica%10;
			printf("\nNumber of 10 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=5)
		{
			show=replica/5;
			left=replica%5;
			printf("\nNumber of 5 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=2)
		{
			show=replica/2;
			left=replica%2;
			printf("\nNumber of 2 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=1)
		{
			show=replica/1;
			left=replica%1;
			printf("\nNumber of 1 rupee note(s) required... %d\n\n", show);
		}
		break;
		
		case 10:
		if(replica>=10)
		{
			show=replica/10;
			left=replica%10;
			printf("\nNumber of 10 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=5)
		{
			show=replica/5;
			left=replica%5;
			printf("\nNumber of 5 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=2)
		{
			show=replica/2;
			left=replica%2;
			printf("\nNumber of 2 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=1)
		{
			show=replica/1;
			left=replica%1;
			printf("\nNumber of 1 rupee note(s) required... %d\n\n", show);
		}
		break;
		
		case 5:
		if(replica>=5)
		{
			show=replica/5;
			left=replica%5;
			printf("\nNumber of 5 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=2)
		{
			show=replica/2;
			left=replica%2;
			printf("\nNumber of 2 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=1)
		{
			show=replica/1;
			left=replica%1;
			printf("\nNumber of 1 rupee note(s) required... %d\n\n", show);
		}
		break;
		
		case 2:
		if(replica>=2)
		{
			show=replica/2;
			left=replica%2;
			printf("\nNumber of 2 rupee note(s) required... %d\n\n", show);
			replica=left;
		}
		
		if(replica>=1)
		{
			show=replica/1;
			left=replica%1;
			printf("\nNumber of 1 rupee note(s) required... %d\n\n", show);
		}
		break;
		
		case 1:
		if(replica>=1)
		{
			show=replica/1;
			left=replica%1;
			printf("\nNumber of 1 rupee note(s) required... %d\n\n", show);
		}
		break;
		
		default:
		printf("\n\nNOT AVAILABLE!!!\n\n");
	}
	
	return;
}


void _form_triads(int n)
{
	int replica1=n, replica2=n*2, replica3=n*3, last_digit1, last_digit2, last_digit3, is_triad=1;
	
	int i=1;
	while(i<=3)
	{
		printf("%d\t", n*i);
		i++;
	}
	
	if(replica2>999)
	{
		printf("\nTriads cannot be formed....%d is not a 3 digit number...\n\n", replica2);
		return;
	}
	
	if(replica3>999)
	{
		printf("\nTriads cannot be formed....%d is not a 3 digit number...\n\n", replica3);
		
		return;
	}
	
	
	// compare n and n*2
	
	while(replica1!=0)
	{
		last_digit1=replica1%10;
		while(replica2!=0)
		{
			last_digit2=replica2%10;
			if(last_digit1==last_digit2)
			{
				is_triad=0;
				break;
			}
			
			replica2/=10;
		}
		
		if(is_triad==0)
		{
			printf("\nNumbers donot form triads...digits were repeated....\n\n");
			return;
		}
		replica2=n*2;
		
		replica1/=10;
	}
	replica1=n;
	
	// compare n*2 and n*3
	
	
	while(replica2!=0)
	{
		last_digit2=replica2%10;
		
		while(replica3!=0)
		{
			last_digit3=replica3%10;
			if(last_digit2==last_digit3)
			{
				is_triad=0;
				break;
			}
			
			replica3/=10;
		}
		
		if(is_triad==0)
		{
			printf("\nNumbers donot form triads...digits were repeated....\n\n");
			return;
		}
		
		replica3=n*3;
		
		replica2/=10;
	}
	
	replica2=n*2;
	
	// compare n and n*3
	
	while(replica1!=0)
	{
		last_digit1=replica1%10;
		
		while(replica3!=0)
		{
			last_digit3=replica3%10;
			if(last_digit1==last_digit3)
			{
				is_triad=0;
				break;
			}
			
			replica3/=10;
		}
		
		if(is_triad==0)
		{
			printf("\nNumbers donot form triads...digits were repeated....\n\n");
			return;
		}
		
		replica3=n*3;
		replica1/=10;
	}
	
	if(is_triad==1)
	{
		printf("\nThe numbers form triads...\n\n");
	}
}