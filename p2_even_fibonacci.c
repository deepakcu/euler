#include <stdio.h>
#include <stdint.h>

/*
https://projecteuler.net/problem=2

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

*/

int main()
{
	int prev = 1, cur = 1;
	uint64_t n = 1;
	uint64_t sum = 0;

	while(n < 4000000) {
		prev = cur;
		cur = n;
		n = prev+cur;
		if(n % 2 == 0)
			sum += n;
	}
	printf("%ld\n", sum);	
}