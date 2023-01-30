#include <stdio.h>

#define LOWER  0	/* lower bound of temps */
#define STEP  20	/* step portion of for loop  */
#define UPPER  300 /* upper bound of temps */ 

//Table Convertor for F to C
int main()
{
	int fahr, cels;
	printf("F\tC\n");
	for(fahr=LOWER; fahr<=UPPER; fahr+=STEP)
	{
		cels= 5 * (fahr-32) / 9;
		
		printf("%d\t%d\n", fahr, cels);
	}
	printf("\nBetter Format\nF\t|C\n---------------\n");
	
	float fahren, celsius;
	for(fahr=UPPER; fahr>=LOWER; fahr-=STEP)
	{
		fahren=fahr;
		celsius= 5.0/9.0 * (fahren-32.0);
		
		printf("%3.0f\t|%6.1f\n", fahren, celsius);
	}
	return 0;
}