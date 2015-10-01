#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
#include<string.h>

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
/*
int f_rotate(int n, int r) {

	int output, size=log10(n)+1;
	int digits[];

	int i=size, temp=n;
	while(i>=0) {

		digits[i]=temp%10;

		temp/=10;

		i--;
	}

	i=size;
	int shifting=r;
	i-=shifting;
	while(i==size) {

		int value=digits[i];
		for(int k=i; k<0; k--) {

			digits[k]=digits[k-1];

		}

		digits[

	}

}
*/

int main(){

	int problemSet;

	printf("1. f_armstrong\n2. f_bracket\n3. f_perfect\n4. f_rotate");
	printf("\n\nPlease enter the problem wish to test: ");
	scanf("%i", &problemSet);

	if(problemSet==1) {
	// Armstrong number test

		int a=0;

		while(a!=100000){
		//int input;
		//scanf("%d", &input);
		//printf("\nPlease Enter a number: ");
		if(f_armstrong(a)){
			printf("Is ");
			printf("\n\n");
			printf("%d", a);
			printf(" a Armstrong number?");
			printf("\t YES");
		}

		a++;
	}


	}
/* Armstrong number test








	char e[30];
	printf("Please enter the string of Brackets you wish to test: ");
	scanf("%s", e);

	printf("Is  %s",e);
	printf(" balanced?");

	if(f_brackets(e))
		printf("\t YES\n");
	else
		printf("\t NO\n");




	int test;
	printf("Perfect number? Check: ");
	scanf("%i", &test);

	printf("Is %i", test);
	printf(" a pefect number?");

	if(f_perfect(test))
		printf("\t YES \n");

	else
		printf("\t NO \n");

*/


	return 0;
}


