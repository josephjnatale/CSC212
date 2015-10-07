#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>


int *f_cubes_sum (int n) {

	int numbers[2]={0}, *p;
	bool comboFound=false;


	for(int i=0; i<=1000; i++) {

		for(int j=0; j<=1000; j++) {

			printf("\nDoes %d^3 + %d^3= %d", i,j,n);

			if(pow(i,3)+pow(j,3)==n) {
				printf("YES!!!");
				comboFound=true;
				numbers[0]=i;
				numbers[1]=j;
				break;
			}

			printf("\tNo %d", (int)(pow(i,3)+pow(j,3)));
			if(pow(i,3)+pow(j,3)>n){
				break;
			}
		}
			
		if(comboFound)
			break;	
		if(pow(i,3)>n){
				break;
			}

	}

	if(comboFound) {
		p=numbers;
		return p;
	}
	else {
		numbers[0]=(int)NULL;
		numbers[1]=(int)NULL;
		p=numbers;
		return p;
	}
}



void f_sort (int x, int y, int z, int *numbers) {

	static int list[3];
	if(x>y && x>z) {
		list[0]=x;

		if(y>z) {
			list[1]=y;
			list[2]=z;
		}
		else {
			list[1]=z;
			list[2]=y;
		}
	}

	if(y>x && y>z) {
		list[0]=y;

		if(x>z) {
			list[1]=x;
			list[2]=z;
		}
		else {
			list[1]=z;
			list[2]=x;
		}
	}

	if(z>x && z>y) {
		list[0]=z;

		if(x>y) {
			list[1]=x;
			list[2]=y;
		}
		else {
			list[1]=y;
			list[2]=x;
		}
	}

	// for(int i=2; i==0; i--) {
	// 	printf("%d, ", list[i]);
	// }

	*(numbers)=list[2];
	*(numbers+1)=list[1];
	*(numbers+2)=list[0];
}



void f_strings(char *s1, char *s2, char *s3) {
	int s1Length= strlen(s1), s2Length=strlen(s2);

	if(s1Length<s2Length) {

		char output[2*s1Length +s2Length];

		int j=0, k=0, l=0;
		for(j=0; j<s1Length; j++) 
			output[j]=s1[j];

		for(k=0; k<s2Length; k++) 
			output[j+k] = s2[k];
		
		for(l=0; l<s1Length; l++) 
			output[j+k+l] = s1[l];


		s3=output;
		printf("%s", s3);
	}

	else {

		char output[2*s2Length +s1Length];

		int j=0, k=0, l=0;
		for(j=0; j<s1Length; j++) 
			output[j]=s2[j];

		for(k=0; k<s2Length; k++) 
			output[j+k] = s1[k];
		
		for(l=0; l<s1Length; l++) 
			output[j+k+l] = s2[l];

		
		s3=output;
		printf("%s", s3);
	}

}

float f_array(int n) {

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

 		if(A[i]%3==0 && A[i]!=0 && collected<6){
 			B[collected]=A[i];
 			collected++;
 		}
 		i++;
 	}
 	printf("\nNumber collected: %i\n", collected);
 	float total=0;
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

int f_str_search(char *pattern, char *text) {
	
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


}

int f_rotate(int n, int r) {

	int size=floor(log10(n))+1, number[size], index, temp=n, counter;

	//if rotated more than size, will move the same as r%size;
	if(r>=size)
		r%=size;
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
	//printf("\n");
	while(temp!=0) {

		if(temp<=1)
			temp=0;

		temp= round((float)temp/2);
		//printf("%i",temp);
		//printf("+");
		total+=temp;

	}
	//printf("0=%i",total);
	if(total==n)
		return true;

	else
		return false;
}


bool f_brackets(char *e) {

	char leftBracket = '[', rightBracket = ']';
	int j=0,LBcount=0, RBcount=0, length=strlen(e);


	if(length==1 || e[0]==rightBracket)
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

