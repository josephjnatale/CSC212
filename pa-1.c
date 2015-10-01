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

int f_rotate(int n, int r) {

	int output, size=log10(n);
	int digits[size], movingDigits[r];

	int i=size, temp=n, position=0;
	while(i>=0) {

		digits[i]=temp%10;

		temp/=10;
		printf("|%i",digits[i]);
		i--;
	}

	//reverse digit array
	int switching;
	for(int s=0; s<size/2+1; s++) {

		switching=digits[size-s];
		digits[size-s-i]=digits[s];
		digits[s]=switching;
	}
	printf("\n");
	//prints all digits
	for(int k=0; k<size+1; k++) {

		printf("|%i",digits[k]);
	}


	i=r;
	while(i>=0) {

		digits[size-i-1]=movingDigits[position];

		position++;
		i--;
	}

	//move digits to the right r times

	for(int j=size-r; j>0; j--) {

		digits[j+r]=digits[j];
	}
	for(int q=0; q<r; q++) {

		digits[q]=movingDigits[q];
	}

	int returnValue=0;

	for(int p=size; p>0;p--)
	{
		returnValue+=(pow(10, p-1)*digits[p-1]);
	}
	
	return returnValue;
}


int main(){

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

			printf("\nRotated number: %i", f_rotate(n,r));

		}


		else if(problemSet==0) 
			exit=true;

	}

	return 0;
}


