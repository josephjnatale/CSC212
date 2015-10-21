#include <stdio.h>

int main() {

	int days, i, j,  age, size;
	scanf("%i", &days);

	int inputs[days][2];

	for(i=0; i<days; i++){
	
		scanf("%i %i",&inputs[i][0],&inputs[i][1]);	

	}

	for(j=0; j<days; j++){
	
		if(inputs[j][0]<18 && inputs[j][1]<350000)
			printf("\nBreakfast #%i: 4", j+1);

		else if(inputs[j][0]>=18 && inputs[j][1]<350000)
			printf("\nBreakfast #%i: 5", j+1);

		else if(inputs[j][1]>=350000)
			printf("\nBreakfast #%i: 0", j+1);

		
	

	
	


	}
	

return 0;

}
