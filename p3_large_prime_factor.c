#include <stdio.h>
#include <stdint.h>

/*
https://projecteuler.net/problem=3

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

int main()
{
	uint64_t num = 600851475143;
	uint64_t div_by = 2;

	while (div_by < num) {
		if (num % div_by == 0) {
			while (num % div_by == 0)
				num = num / div_by;
		} else {
			div_by++;
		}
	}
	printf("%ld\n", div_by);
}
