//#include <sys/types.h>
#include <stdlib.h>

#include "headers/parser_format.h"
#include "headers/utils.h"

t_flags *create_flags()
{
	t_flags *flags = (t_flags *) malloc(sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	flags->zero_pad = 0;
	flags->justify_left = 0;
	flags->sign = 0;
	flags->hash = 0;
	flags->space = 0;
	//todo
	flags->min = 0;
	flags->max = 0;
	return (flags);]
}

char *parse_pad(char *s, t_flags *flags)
{
	if(*s == '*' && ++s) //min width
	{}
	else if (ft_isdigit(s)) 
		s = q_atoi(s, &flags->min);
	if (*s == '.' && ++s) //period
	{
		if (*s == '*' && ++s) //max width
		{}
		else if (ft_isdigit(*s))
			s = q_atoi(s, &flags->max);
	}
	return (s);
}

void init_s_pad(size_t len, t_flags *flags)
{
	if (len < flags->max)
		flags->max = len;

	if (flags->min < flags->max)
		flags->min = flags->max;
}

char *parse_flags(const char *s, t_flags **flags)
{
	*flags = create_flags();
	if (*flags == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == '-' && !flags->justify_left)
			flags->justify_left = true;
		else if (*s == '+' && !flag->sign)
			flags->sign = true;
		else if (*s == ' ' && !flags->space)
			flags->space = true;
		else if (*s == '0' && !flags->zero_pad)
			flags->zero_pad = true;	
		else if (*s == '#' && !flags->hash)
			flags->hash = true;
		else if (ft_strchr_bool("-+ 0#", *s)) //flag happen twice tothink ?use bitenum
			return (NULL);
		else
			break;
		++s;
	}
	return (s);
}


/*
void format_s_pad(char *s, t_pad (*pad)
{
	//size_t len = ft_strlen(s);
	//size_t i = 0;
	size_t max; //max data from src
	size_t min; //min output from vdd

	if (len > pad->max) //s need crop
		max = pad->max
	else
		max = len;

	if (pad->min > max) //s need pad
		min = pad->min;
	else
	{
		min = max;
		//write(1, s, max);
		//return ;
	}
	/*
	if (pad->justify_left) //add pad char right
	{
		i = 0;
		while (i < min-max && ++i)
			write(1, " ", 1);
		write(1, s, max);
		return ;
	}

	write(1, s, max);
	i = 0;
	while (i < min-max && ++i)
		write(1, " ", 1);
	*/