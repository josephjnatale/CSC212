#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
#include<string.h>

bool f_armstrong(int);
bool f_brackets(char e[]);
bool f_perfect(int n);
int f_rotate(int n, int r);
int f_str_search(char pattern[], char text[]);


int main() {

	bool exit=false;

	while(!exit) {

		//Main test all possible outcomes. 
		int problemSet;

		printf("\n\n1. f_armstrong\n2. f_bracket\n3. f_perfect\n4. f_rotate");
		printf("\n\nPlease enter the problem wish to test [enter 0 to exit]: ");
		scanf("%i", &problemSet);

		if(problemSet==1) {
		// Armstrong number test

			int a=0;

			//checks all possible number between 1 and 100000 prints only if it is a armstrong number
			while(a!=100000){

				//for entering your own number	
				//int input;
				//scanf("%d", &input);
				//printf("\nPlease Enter a number: ");

				if(f_armstrong(a))	{
					printf("\n\n");
					printf("Is ");
					printf("%d", a);
					printf(" a Armstrong number?");
						
					printf("\t YES");
				}
				a++;
			}
		}
		
		else if(problemSet==2) {

			char e[30];
			printf("Please enter the string of Brackets you wish to test: ");
			scanf("%s", e);

			printf("Is  %s",e);
			printf(" balanced?");

			if(f_brackets(e))
				printf("\t YES\n");
			else
				printf("\t NO\n");

		}

		else if(problemSet==3) {
			
			int test;
			printf("Perfect number? Check: ");
			scanf("%i", &test);

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
			char pattern[10], text[100];

			printf("\nEnter the pattern: ");
			scanf("%s", pattern);
			printf("\nEnter the text you which to cross check: \n");
			scanf("%s", text);

			printf("\nTimes pattern is shown in text: %i", f_str_search(pattern, text));

		}


		else if(problemSet==0) 
			exit=true;

		printf("\n====================================================================================\n");
	}

	return 0;
}

int f_str_search(char pattern[], char text[]) {
	
	int length=strlen(text);
	
	printf("%i", length);

	return 666;
}
int f_rotate(int n, int r) {

	int size=floor(log10(n))+1, number[size], index, temp=n, counter;

	//places each digit into the array
	for(index=0; index<=size; index++) {
		number[size-1-index]=temp%10;
		temp/=10;
	}

	//prints array
	for(index=0; index<=size-1; index++) {
		printf("|%i",number[index]);
	}

	//creates 2nd array to store ending r values in
	int switchingNumbers[r];

	//puts ending r values in switchingNumbers array
	counter=0;
	for(index=size-r; index<=size-1; index++) {
		switchingNumbers[counter]=number[index];
		counter++;
	}

	for(index=0; index<=r-1; index++) {
		printf("\n%i", switchingNumbers[index]);
	}

	//shifts all remaing number to the right r times
	for(index=(size-(counter+1)); index>-1; index--) {
		printf("\nMoving %i where %i was",number[index], number[index+1]);
		number[index+r]=number[index];
	}

	printf("\n");

	for(index=0; index<=size-1; index++) {
		printf("| %i", number[index]);
	}

	//places switchingNumbers into number array
	for(index=0; index<=r-1; index++) {
		number[index]=switchingNumbers[index];
	}

	printf("\n");
	for(index=0; index<=size-1; index++) {
		printf("| %i", number[index]);
	}

	//converts number array to integer
	int total=0;
	for(index=0; index<size; index++)
		total = 10 * total + number[index];

	return total;

}

bool f_perfect(int n) {

	int total=0, temp;

	temp=n;
	printf("\n");
	while(temp!=0) {

		if(temp<=1)
			temp=0;

		temp= round((float)temp/2);
		printf("%i",temp);
		printf("+");
		total+=temp;

	}
	printf("0=%i",total);
	if(total==n)
		return true;

	else
		return false;
}


bool f_brackets(char e[]) {

	char leftBracket = '[', rightBracket = ']';
	int j=0,LBcount=0, RBcount=0, length=strlen(e);


	if(length==1)
		return false;

	while(j != length) {

		if(e[j]==leftBracket)
			LBcount++;
		else if(e[j]==rightBracket)
			RBcount++;
		else
			return false;

		j++;
	}

	if(LBcount== RBcount){

		int midpoint = length/2;

		for(int i=0; i<midpoint; i++) {

			if(e[i]==leftBracket && e[length-i-1]!=rightBracket)
				return false;

			else if(e[i]==rightBracket && e[length-i-1]!=leftBracket)
				return false;
		}

		return true;
	}
	else
		return false;

}

bool f_armstrong(int n) {

	int  digits=0, number, temp, total=0;


	temp=n;
	while(temp!=0) {
		digits+=1;
		temp/=10;
	}

	temp=n;
	for(int i =0; i<digits; i++) {
		number=temp%10;
		total=total+pow(number, digits);
		temp/=10;
	}


	if(total==n)
		return true;

	else
		return false;



}

