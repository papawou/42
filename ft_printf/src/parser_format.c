//#include <sys/types.h>
#include <stdlib.h>

#include "headers/parser_format.h"
#include "headers/parser_utils.h"

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
	
	flags->min = -1;
	flags->max = -1;
	return (flags);
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

char *parse_flags(const char *s, t_flags **flags)
{
	*flags = create_flags();
	if (*flags == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == '-' && !(*flags)->justify_left)
			(*flags)->justify_left = true;
		else if (*s == '+' && !(*flags)->sign)
			(*flags)->sign = true;
		else if (*s == ' ' && !(*flags)->space)
			(*flags)->space = true;
		else if (*s == '0' && !(*flags)->zero_pad)
			(*flags)->zero_pad = true;	
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