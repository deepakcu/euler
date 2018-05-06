#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*

https://projecteuler.net/problem=20

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

*/

#define MAX_DIGITS 1000

void product(int *a, int b, int *cin, int *prod, int *cout) {
	int m = *a;
   int n = b;
	int c_in = *cin;
   *prod = (m * n + c_in) % 10;
   *cout = (m * n + c_in) / 10;
}

int main()
{
	int prev_fac[MAX_DIGITS], cur_fac[MAX_DIGITS], parA[MAX_DIGITS], parB[MAX_DIGITS], res[MAX_DIGITS+1];
   int i = 0;

	for(i = 0; i < MAX_DIGITS; i++) {
		prev_fac[i] = 0;
		cur_fac[i] = 0;
	}

	prev_fac[MAX_DIGITS-1] = 9;
	int cin = 0;
	int cout = 0;
	for(i = 0; i<MAX_DIGITS; i++) {
		product(&prev_fac[MAX_DIGITS-1-i], 9, &cin, &parA[MAX_DIGITS-1-i], &cout);
		cin = cout;
	}
   
	cin = 0;
	cout = 0;

	for(i = 0; i<MAX_DIGITS-1; i++) {
		product(&prev_fac[MAX_DIGITS-1-i], 4, &cin, &parB[MAX_DIGITS-2-i], &cout);
		cin = cout;
	}

	for(i=0; i<MAX_DIGITS; i++) {
		if(parA[i] != 0) {
			printf("%d,", parA[i]); 
		}		
	}
	printf("\n");

	for(i=0; i<MAX_DIGITS; i++) {
		if(parB[i] != 0) {
			printf("%d,", parB[i]); 
		}
	}

	int carry = 0;
	for(i=0; i<MAX_DIGITS-2; i++) {
		if(i==0)
			res[MAX_DIGITS-1-i] = parA[MAX_DIGITS-1-i];
		else {
			res[MAX_DIGITS-1-i] = (parA[MAX_DIGITS-2-i]+parB[MAX_DIGITS-1-i]+carry)  % 10;
			carry = (parA[MAX_DIGITS-i-2] + parB[MAX_DIGITS-i-1] + carry)  / 10;
		}
	}

	printf("\n");
	for(i=0; i<MAX_DIGITS; i++) {
			printf("%d,", res[i]); 
	}

	printf("\n");
}
