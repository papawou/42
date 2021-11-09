#include <sys/types.h>
#include <stdlib.h>
#include "get_next_line.h"

char	get_next_c_book(t_page **page, char **cursor)
{
	t_page *tmp_page;
	char c;
	if (**cursor == 0)
	{
		tmp_page = *page;
    *page = (*page)->next;
		free_page(tmp_page);
		if (*page)
			*cursor = (*page)->content;
		else
		{
			*cursor = NULL;
			return 0;
		}
	}
	c = **cursor;
	*cursor = *cursor + 1;
	return (c);
}

char *gen_out(t_page **entry_page, char **entry_cursor, size_t len_out)
{
	char	*out;
	size_t	i;

	if (len_out < 1)
		return (NULL);
	out = malloc(len_out + 1);
	if (out == NULL)
		return (NULL);
	out[len_out] = 0;
	i = 0;
	while (i < len_out)
		out[i++] = get_next_c_book(entry_page, entry_cursor);
	return (out); 
}

char	*get_next_line(int fd)
{
	static int 		_fd = 0;
	static t_page *entry_page = NULL;
	static char   *entry_cursor = NULL;
	static ssize_t len_line = 0;
	char *out;
	size_t next_line;

	if (_fd != fd)
	{
		_fd = fd;
		free_page(entry_page);
		entry_page = NULL;
		entry_cursor = NULL;
	}
	if (entry_page == NULL) //first read
	{
		len_line = gen_page(&entry_page, fd);
		if (len_line < 1)
			return (NULL);
		entry_cursor = entry_page->content;
	}
	next_line = read_book(entry_page, entry_cursor, &len_line, fd);
	out = gen_out(&entry_page, &entry_cursor, len_line - next_line);
	len_line = next_line;
	return (out);
}
