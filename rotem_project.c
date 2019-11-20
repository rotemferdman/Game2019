#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


#define EASY 1
#define MED 2
#define HARD 3
#define CRAZY 4
#define MAX_EASY 20
#define FROM_C_TO_I 48 //from char to int
#define EXIT 5
#define MAX_VALEUE 6
#define MAX_C 54 //max char value
#define MIN_C 49
#define MAX_MED 15
#define MAX_HARD 10
#define MIN_ATT 5 //min and max of the crazy round
#define MAX_ATT 25

void game(int x);
void crazy();


    int num1G = 0; //all the code numbers
	int num2G = 0;
	int num3G = 0;
	int num4G = 0;
	
	char u1G = 0; //the numbers that user is putting to guess (u for user).
	char u2G = 0;
	char u3G = 0;
	char u4G = 0;


int main()
{
	system("COLOR F");
	int lvl = 0;
	int x = MAX_EASY;
	int y = MAX_MED;
	int z = MAX_HARD;
	//the rules, story and level difficultey.
	
	printf("A secret password was chosen to protect the credit card of Pancratius,\n");
	printf("the descendant of Antiochus.\n");
	printf("Your mission is to stop Pancratius by revealing his secret password.\n");
	printf("\n");
	printf("The rules are as follows:\n");
	printf("1. In each round you try to guess the secret password (4 distinct digits)\n");
	printf("2. After every guess you'll receive two hints about the password\n");
	printf(" HITS:   The number of digits in your guess which were exactly right.\n");
	printf("MISSES: The number of digits in your guess which belongs to\n");
	printf("  the password but were miss-placed.\n");
	printf("3. If you'll fail to guess the password after a certain number of rounds\n");
	printf(" Pancratius will buy all the gifts for Hanukkah!!!\n");
	
	lvl = 0; 
	
	printf("choose a difficultey level\n");
	printf("1 - easy\n");
	printf("2 - medium\n");
	printf("3 - hard\n");
	printf("4 - crazy\n");
	printf("5 - exit\n");
	scanf("%d", &lvl);
	
	while(lvl > EXIT || lvl < EASY)
	{
		printf(" please choose a vaild number\n");
		scanf("%d", &lvl);
	}
	
	switch (lvl)
	{
		case EASY:
		game(x);
		break;
		
		case MED:
		game(y);
		break;
		
		case HARD:
		game(z);
		break;
		
		case CRAZY:
		crazy();
		break;

		default:
		return 0;
		break;
	}
}

void game(int x)
{
	if(x == MAX_EASY) //changing the color
	{
		system("COLOR 1");
	}
	else if(x == MAX_MED)
	{
		system("COLOR 6");
	}
	else if(x == MAX_HARD)
	{
		system("COLOR 4");
	}
	system("CLS");
	int i = 0; //the guesses
	
	int u1 = 0; //the int versions of the numbers.
	int u2 = 0;
	int u3 = 0;
	int u4 = 0; 
	int attempts = x; //show the attempts that left
	int hits = 0; //the number of hits
	int misses = 0; //the number of misses.
	
	srand(time(NULL)); //random numbers giving
	
	while(num1G == 0)
	{
	num1G = rand() %6 + 1;
	}
	while(num2G == num1G || num2G == 0) //checking that theres no multipele numbers.
	{
	num2G = rand() %6 + 1;
	}
	while(num3G == num2G || num3G == num1G || num3G == 0)
	{
	num3G = rand() %6 + 1;
	}
	while(num4G == num3G || num4G == num2G || num4G == num1G || num4G == 0)
	{
	num4G = rand() %6 + 1;
	}
	
	
	for(i == 0; i < x; i++)
	{
		
		printf("\n");
		printf("\n %d attempts left\n", attempts);
		attempts = attempts - 1;
		
		do //getting numbers and checking that theres diffrent numbers and no 0 or x>6.
		{
		printf("\n");
		printf("please choose numbers from 1 -6, diffrent number in each one, no ENTER needed\n");
		printf("\n");
		u1G = getch();
		putch(u1G);
		u2G = getch();
		putch(u2G);
		u3G = getch();
		putch(u3G);
		u4G = getch();
		putch(u4G);
		}
		while(u1G == u2G || u1G == u3G || u1G == u4G || u2G == u3G || u2G == u4G || u3G == u4G || u1G > MAX_C || u1G < MIN_C || u2G > MAX_C || u2G < MIN_C || u3G > MAX_C || u3G < MIN_C || u4G > MAX_C || u4G < MIN_C);
		
		u1 = u1G - FROM_C_TO_I;
		u2 = u2G - FROM_C_TO_I;
		u3 = u3G - FROM_C_TO_I;
		u4 = u4G - FROM_C_TO_I;
		
		
		if(u1 == num1G) //hit 1st number
		{
			hits = hits + 1;
		}
		if(u2 == num2G) //hit 2nd number
		{
			hits = hits + 1;
		}
		if(u3 == num3G) //hit 3rd number
		{
			hits = hits + 1;
		}
		if(u4 == num4G) //hit 4th number
		{
			hits = hits + 1;
		}
		if(u1 == num2G || u1 == num3G || u1 == num4G)
		{
			misses = misses + 1;
		}
		if(u2 == num1G || u2 == num3G || u2 == num4G)
		{
			misses = misses + 1;
		}
		if(u3 == num1G || u3 == num2G || u3 == num4G)
		{
			misses = misses + 1;
		}
		if(u4 == num1G || u4 == num2G || u4 == num3G)
		{
			misses = misses + 1;
		}			
		
		
		
		printf("\n                       %d hits,       %d misses\n", hits, misses); 
		
		if(hits == CRAZY) //victory
		{	
			printf("yay!!! you won!!!! see you next time!\n");
			printf("\n");
			printf("\n");
			printf("\n");
			 main();
		}
		misses = 0;
		hits = 0;
		
	}
	printf("the code was %d %d %d %d\n", num1G, num2G, num3G, num4G);
	printf("sorry, you lost... maybe next time?\n"); //losing
	printf("\n");
	printf("\n");
	printf("\n");
	main();
}

void crazy()
{
	system("CLS");
	system("COLOR 8");
		int i = 0; //the guesses
	
	int u1 = 0; //the int versions of the numbers.
	int u2 = 0;
	int u3 = 0;
	int u4 = 0; 
	int attempts = 0; //show the attempts that left
	int hits = 0; //the number of hits
	int misses = 0; //the number of misses.
	
	srand(time(NULL)); //random numbers giving
	
	while(attempts < MIN_ATT || attempts > MAX_ATT)
	{
		attempts = rand();
	}
	
	while(num1G == 0)
	{
	num1G = rand() %6 + 1;
	}
	while(num2G == num1G || num2G == 0) //checking that theres no multipele numbers.
	{
	num2G = rand() %6 + 1;
	}
	while(num3G == num2G || num3G == num1G || num3G == 0)
	{
	num3G = rand() %6 + 1;
	}
	while(num4G == num3G || num4G == num2G || num4G == num1G || num4G == 0)
	{
	num4G = rand() %6 + 1;
	}
	
	
	for(i == 0; i < attempts; i++)
	{
		
		printf("\n");
		attempts = attempts - 1;
		
		do //getting numbers and checking that theres diffrent numbers and no 0 or x>6.
		{
		printf("\n");
		printf("please choose numbers from 1 -6, diffrent number in each one, no ENTER needed\n");
		printf("\n");
		u1G = getch();
		putch(u1G);
		u2G = getch();
		putch(u2G);
		u3G = getch();
		putch(u3G);
		u4G = getch();
		putch(u4G);
		}
		while(u1G == u2G || u1G == u3G || u1G == u4G || u2G == u3G || u2G == u4G || u3G == u4G || u1G > MAX_C || u1G < MIN_C || u2G > MAX_C || u2G < MIN_C || u3G > MAX_C || u3G < MIN_C || u4G > MAX_C || u4G < MIN_C);
		
		u1 = u1G - FROM_C_TO_I;
		u2 = u2G - FROM_C_TO_I;
		u3 = u3G - FROM_C_TO_I;
		u4 = u4G - FROM_C_TO_I;
		
		if(u1 == num1G) //hit 1st number
		{
			hits = hits + 1;
		}
		if(u2 == num2G) //hit 2nd number
		{
			hits = hits + 1;
		}
		if(u3 == num3G) //hit 3rd number
		{
			hits = hits + 1;
		}
		if(u4 == num4G) //hit 4th number
		{
			hits = hits + 1;
		}
		if(u1 == num2G || u1 == num3G || u1 == num4G)
		{
			misses = misses + 1;
		}
		if(u2 == num1G || u2 == num3G || u2 == num4G)
		{
			misses = misses + 1;
		}
		if(u3 == num1G || u3 == num2G || u3 == num4G)
		{
			misses = misses + 1;
		}
		if(u4 == num1G || u4 == num2G || u4 == num3G)
		{
			misses = misses + 1;
		}			
		
		
		
		printf("\n                       %d hits,       %d misses\n", hits, misses); 
		
		if(hits == CRAZY) //victory
		{
			printf("yay!!! you won!!!! see you next time!\n");
			printf("\n");
			printf("\n");
			printf("\n");
			 main();
		}
		misses = 0;
		hits = 0;
		
	}
	printf("sorry, you lost... maybe next time?\n"); //losing
	printf("\n");
	printf("\n");
	printf("\n");
	main();
}

