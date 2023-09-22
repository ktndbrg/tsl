#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <tgmath.h>

/*
  Making this recursive will break the stack eventually.
  Also to avoid integer overflow return the type double.
  Gamma function is better if you want precision but is slower.
*/
double factorial (double n)
{
	/* Quick error checking */
	if (n < 0.0) {
		fprintf (stderr, "Error in factorial(), n < 0.0\n");
		return (1.0);
	}

	double product = 1.0;
	for (int i = 1; i < (int) n + 1; i++) {
		product *= i;
	}

	return (product);
}

/*
  nPr, Pnr.
  Permutations of n objects taken r at a time.
  
  If we want to bypass the function factorial
  this could be implemented as:
  product = n * (n-1) * (n-2) * ... * (n-r+1);
*/
double permutations (double n, double r)
{
	if (n < r || n < 0.0 || r < 0.0) {
		fprintf (stderr, "Error in permuations, invalid argument nPk(%g, %g)\n", n, r);
	}

	return (factorial (n) / factorial (n - r));
}

int main (void)
{
	for (int i = -2; i < 5; i++) 
		printf ("factorial(%d) = %.2f\n", i, factorial (i));

	printf ("factorial(%d) = %.10E\n", 100, factorial (100));
	printf ("permutations(%d, %d) = %g\n", 9, 3, permutations(9, 3));
	return (0);
}

