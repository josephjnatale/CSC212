#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "pa-1.h"


bool f_armstrong(int);
bool f_brackets(char *e);
bool f_perfect(int n);
int f_rotate(int n, int r);
int f_str_search(char *pattern, char *text);
int f_collatz_count(int n);
float f_array(int n);
void f_strings(char *s1, char *s2, char *s3);
void f_sort (int x, int y, int z, int *list);
int *f_cubes_sum(int n);


int main() {

	bool exit=false;

	while(!exit) {

		//Main test all possible outcomes. 
		int problemSet;

		printf("\n\n1. f_armstrong\n2. f_bracket\n3. f_perfect\n4. f_rotate\n5. f_str_search\n6. f_collatz_count\n7. f_array\n8. f_strings\n9. f_sort\n10. f_cubes_sum\n");
		printf("\n\nPlease enter the problem wish to test [enter 0 to exit]: ");
		scanf("%i", &problemSet);

		if(problemSet==1) {
		
			//for entering your own number	
			int input;
			
			printf("\nPlease Enter a number: ");
			scanf("%d", &input);
			printf("\n\n");
			printf("Is ");
			printf("%d", input);
			printf(" a Armstrong number?");

			if(f_armstrong(input))
				printf("\t YES");
			
			else 
				printf("\t NO");
			
		}
		
		else if(problemSet==2) {

			char e[30];
			char *p = e;
			printf("Please enter the string of Brackets you wish to test: ");
			scanf("%s", e);

			printf("Is  %s",e);
			printf(" balanced?");

			if(f_brackets(p))
				printf("\t YES\n");
			else
				printf("\t NO\n");

		}

		else if(problemSet==3) {
			
			int test;
			printf("Perfect number? Check: ");
			scanf("%i", &test);
		
			printf("\n\n");
			printf("Is %i", test);
			printf(" a pefect number?");
		
			if(f_perfect(test))
				printf("\t YES \n");

			else
				printf("\t NO \n");
		}

		else if(problemSet==4) {
			int n, r;

			printf("Please enter n, the number you wish to rotate \nn: ");
			scanf("%i", &n);
			printf("\nPlease enter r, the number  you wish to rotate by \nr: ");
			scanf("%i", &r);

			printf("\nResult: %i", f_rotate(n,r));

		}

		
		else if(problemSet==5) {
			char pattern[10], text[50];
			char *pPattern=pattern, *pText=text;

			printf("\nEnter the pattern: ");
			scanf("%s", pattern);

			printf("\nEnter the text you which to cross check: \n");
			scanf("%s", text);

			
			printf("\nTimes pattern is shown in text: %i", f_str_search(pPattern, pText));
			printf("\n**NOT WORKING, NOT SURE WHY, DID NOT HAVE ENOUGH TIME TO FIX THE BUG**");

		}
		

		else if(problemSet==6) {

			int number;
			printf("\nPlease enter a number n: ");
			scanf("%i", &number);

			printf("\n\nNumber of iterations needed: %i", f_collatz_count(number));

		}

		else if(problemSet==7) {

			int number;
			printf("\nPlease enter a number n: ");
			scanf("%i", &number);

			printf("\n\nAverage: %f", f_array(number));

		}

		else if(problemSet==8) {
			char s1[50],s2[50],s3[150];

			

			printf("\nEnter the first String: ");
			scanf("%s", s1);
			printf("\nEnter the second String: ");
			scanf("%s", s2);
			
			char *p1=s1, *p2=s2, *p3=s3;
			f_strings(p1,p2,p3);

			for(int i=0; i<=strlen(s3); i++) {
				printf("%c", *(s3+i));
			}
		}

		else if(problemSet==9) {

			int n1, n2, n3;
			printf("Please enter three numbers you wish to sort.\nFirst number: ");
			scanf("%i", &n1);
			printf("\nSecond number: ");
			scanf("%i", &n2);
			printf("\nThird number: ");
			scanf("%i", &n3);

			int sorted[3]={0};
			int *pointer=sorted;


			f_sort(n1,n2,n3, pointer);

			for(int i=0; i<3; i++)
				printf("%d, ", sorted[i]);

		}

		else if(problemSet==10) {

			int  input;
			printf("Please enter a number: ");
			scanf("%d", &input);
			int *p=f_cubes_sum(input);

			if(p[0]!=0 && p[1]!=0)
				printf("\nNumbers that work: %d , %d", p[0], p[1]);
			else
				printf("\nNumbers that work: NULL, NULL");

		}


		else if(problemSet==0) 
			exit=true;

		printf("\n====================================================================================\n");
	}

	return 0;
}
