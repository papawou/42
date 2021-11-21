#include <stdio.h>
#include <limits.h>

#include "t_flags.h"
#include "ft_printf.h"

int main()
{
	//t_flags flags = {.blank = 1, .hash = 0, .plus = 1, .zero = 1, .minus = 0, .width = 10, .precision = 0};
	//flags.zero = (flags.zero && !flags.minus && flags.precision == -1);
	//flags.blank = flags.blank && !flags.plus;
	char *s = "%.5s";
	printf("EXAMPLE\n");
	printf("-%d", printf(s, "12"));

	printf("\nTEST\n");
	printf("-%d", ft_printf(s, NULL));
} 