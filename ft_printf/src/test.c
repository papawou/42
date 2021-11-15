#include "headers/format_types.h"

#include <unistd.h>
#include <sys/types.h>
#include "ft_utils.h"

void ft_putstr(char *s)
{
	size_t i;
	i = 0;
	while(s[i])
		write(1, s + i++, 1);
}

int main(void)
{
	t_flags flags = {.blank = 0, .hash = 0, .plus = 0, .zero = 1, .minus = 0, .width = 10, .precision =2};
	char *s = format_s("abc", &flags);
	ft_putstr(s);
	return 0;
}