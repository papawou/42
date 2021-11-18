//#include <sys/types.h>
#include <stdlib.h>

#include "headers/ft_utils.h"
#include "headers/t_flags.h"

t_flags *create_flags()
{
	t_flags *flags = (t_flags *) malloc(sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->hash = 0;
	flags->blank = 0;
	
	flags->width = 0;
	flags->precision = -1;
	return (flags);
}

const char *parse_pad(const char *s, t_flags *flags)
{
	if(*s == '*' && ++s) //min width
	{}
	else if (ft_isdigit(*s))
		s = q_atoi_s(s, &flags->width);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = -flags->width;
	}
	if (*s == '.' && ++s) //precision
	{
		flags->precision = 0;
		if (*s == '*' && ++s)
		{}
		else if (ft_isdigit(*s))
			s = q_atoi_s(s, &flags->precision);
		if (flags->precision < 0)
			flags->precision = 0;
	}
	flags->zero = (flags->zero && !flags->minus && flags->precision == -1);
	flags->blank = flags->blank && !flags->plus;
	return (s);
}

const char *parse_flags(const char *s, t_flags **flags)
{
	*flags = create_flags();
	if (*flags == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == '-' && !(*flags)->minus)
			(*flags)->minus = true;
		else if (*s == '+' && !(*flags)->plus)
			(*flags)->plus = true;
		else if (*s == ' ' && !(*flags)->blank)
			(*flags)->blank = true;
		else if (*s == '0' && !(*flags)->zero)
			(*flags)->zero = true;	
		else if (*s == '#' && !(*flags)->hash)
			(*flags)->hash = true;
		else if (ft_strchr_bool("-+ 0#", *s)) //flag happen twice tothink ?use bitenum
			return (NULL);
		else
			break;
		++s;
	}
	return (s);
}