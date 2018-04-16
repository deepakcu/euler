#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
https://projecteuler.net/problem=4

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

uint64_t reverse(uint64_t num)
{
	uint64_t rev = 0;
	while(num > 0) {
		rev = rev * 10 + num % 10;
		num = num / 10;
	}
	return rev;
}

bool isPalindrome(uint64_t num)
{
	if(num - reverse(num) == 0)
		return true;
	return false;
}

int main()
{
	uint64_t i, j = 999;
	uint64_t prod;
	uint64_t max = 0;

	for (i = 999; i >= 100; i--) {
		for (j = 999; j >= 100; j--) {
			prod = i * j;
			if(isPalindrome(prod)) {
				if(prod > max)
					max = prod;
			}
		}
	}
	printf("%ld\n", max);
	return 0;
}
