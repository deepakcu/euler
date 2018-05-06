#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
https://projecteuler.net/problem=5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

*/

int largestPrimeFactor(int n) {
	int largestPrime = 1;
	int i = 2;
	while(i < n) {
		while(n % i == 0)
			n = n / i;
	}
}

int main()
{
	int prod = 1;
	for(int i=2; i<=20; i++) {
		prod *= largestPrimeFactor(i);
	}
	printf("%d\n", prod);
}
