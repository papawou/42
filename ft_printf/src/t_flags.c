#include <stdlib.h>

#include "t_flags.h"

void reset_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->hash = 0;
	flags->blank = 0;
	
	flags->width = 0;
	flags->precision = -1;
}

t_flags *create_flags()
{
	t_flags	*flags; 

	flags = (t_flags *) malloc(sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	reset_flags(flags);
	return (flags);
}