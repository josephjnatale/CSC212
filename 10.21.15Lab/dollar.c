#include <stdio.h>

int main()
{

	int numberOfPeople;
	scanf("%i", &numberOfPeople);

	int people[numberOfPeople];

	for(int i=0; i<numberOfPeople; i++){
	
	scanf("%i", &people[i]);

	}

	for(int j=0; j<numberOfPeople; j++)
		printf("\nPerson #%i: $%i",j+1, people[j]/2);

	return 0;
}
