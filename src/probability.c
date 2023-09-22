/*
    Tandberg Scientific Library (tsl).  
    Copyright (C) 2023  Kristoffer R. Tandberg "kristoffer.r.tandberg@uit.no"

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#define _POSIX_C_SOURCE 2008011L

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
		fprintf (stderr, "Error in factorial(%g)\n", n);
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
		fprintf (stderr, "Error in permuations(%g, %g)\n", n, r);
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

