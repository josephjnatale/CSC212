#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

bool f_armstrong(int);
bool f_brackets(char e[]);
bool f_perfect(int n);
int f_rotate(int n, int r);
int f_str_search(char pattern[], char text[]);
int f_collatz_count(int n);
int f_array(int n);

int main() {

	bool exit=false;

	while(!exit) {

		//Main test all possible outcomes. 
		int problemSet;

		printf("\n\n1. f_armstrong\n2. f_bracket\n3. f_perfect\n4. f_rotate\n5. f_str_search\n6. f_collatz_count\n7. f_array\n");
		printf("\n\nPlease enter the problem wish to test [enter 0 to exit]: ");
		scanf("%i", &problemSet);
		printf("%i", problemSet);

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

		//not working
		/*else if(problemSet==5) {
			char input;

			printf("\nEnter the pattern: ");
			scanf("%s", input);

			int patternLength= strlen(input);
			char pattern[patternLength];
			

			printf("\nFirst character of input: %s", input[0]);
			int i =0;
			while(input[i] !='\0') {
				input[i]='\0';
				i++;
			}


			printf("\nEnter the text you which to cross check: \n");
			scanf("%s", input);

			int textLength = strlen(input);
			char text[textLength];
			

			printf("\nCHECK POINT 1\n");
			printf("\nTimes pattern is shown in text: %i", f_str_search(pattern, text));

		}*/

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

			printf("\n\nAverage: %i", f_array(number));

		}


		else if(problemSet==0) 
			exit=true;

		printf("\n====================================================================================\n");
	}

	return 0;
}

 int f_array(int n) {

 	int A[n];
	srand(time(NULL));

 	for(int i=0; i<=n-1; i++) {

 		A[i]=rand()%100;
 		printf("%i |",A[i]);

 	}

 	printf("\n");
 	for(int i=0; i<=n-1; i++) {

 		A[i]=A[i]*2;

 	}

 	printf("\n");
 	for(int i=0; i<=n-1; i++) {

 		printf("%i |",A[i]);

 	}

	printf("\n");
 	int B[5], collected=0, i=0;

 	while(i<=n-1) {

 		if(A[i]%3==0 && A[i]!=0){
 			B[collected]=A[i];
 			collected++;
 		}
 		i++;
 	}
 	printf("\nNumber collected: %i\n", collected);
 	int total=0;
 	i=0;

 	if(collected>=5) {

	 	while(i<=4) {

	 		total+=B[i];
	 		printf("%i + ", B[i]);
	 		i++;
	 	}

 		return total/5;
 	}
 	else {
 		printf("\nonly %i numbers divisible by 3 in the array.\n", collected);

 		while(i<=collected-1) {

	 		total+=B[i];
	 		printf("%i + ", B[i]);
	 		i++;
	 	}

 		return total/collected;
 	}
 }

int f_collatz_count(int n) {

	int iterationCount=0, current_Number=n;
	printf("%i=",n);

	while(current_Number!=1)
	{
		if(current_Number%2==0){
			current_Number/=2;
			iterationCount++;
		}
		else if(current_Number%2==1) {
			current_Number= 3*current_Number+1;
			iterationCount++;
		}
		printf("%i + ", current_Number);
	}

	printf("0");
	return iterationCount;

}

//not working
/*int f_str_search(char pattern[], char text[]) {
	
	int textLength=strlen(text), patternLength=strlen(pattern), index, counter=0;
	printf("\npattern= %s", pattern);
	printf("\ntext= %s", text);
	printf("\ntext length: %i\n\n\nfirst character of key: %s\n", textLength, &pattern[0]);

	for(index=0; index<=textLength; index++) {
		printf("Checking index %i for the character: ",index);
		printf("%s", &pattern[0]);

		if(text[index]==pattern[0])
		{
			printf("there is a %s at index: %i\nchecking following numbers\n",&pattern[0], index+1);
			for(int k=1; k<=patternLength; k++) {
				if(text[index+k]!=pattern[k])
					break;

				counter++;
			}
		}
	}

	return counter;

}*/

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

