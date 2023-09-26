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

#define MAX_ITER 1E9
#define EPSILON 1.0E-9

typedef double (*f)(double) func_ptr;
double solve (func_ptr, double lower, double upper)
{
    if ((func_ptr(lower) * func_ptr(upper) >= 0.0)) {
        fprintf (stderr, "Error in solve(%p, %g, %g)\n", func_ptr, lower, upper);
        return (NAN);
    }
    
    double mid = 0.0;
    for (int i = 0; i < MAX_ITER || func_ptr(mid) < EPSILON; i++) {
        mid = (lower + upper) / 2.0;
        if (func_ptr(lower) * func_ptr(mid) < 0.0) {
            upper = mid;
        }
        else {
            lower = mid;
        }
    }

    return (mid);
}

double f (double x)
{
	return (x * x * x * x * x - x - 1.0);
}

int main (void)
{
	printf ("Root of f(x) is located at x = %2.6g\n", solve(f, 1.0, 2.0));

	return (0);
}
