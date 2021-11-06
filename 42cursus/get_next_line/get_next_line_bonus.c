#include "get_next_line_bonus.h"

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
	static t_book *entry_book = NULL;
	char					*out;
	t_book				*c_book;

	c_book = get_fd_book(&entry_book, fd);
	if (c_book == NULL)
		return (NULL);
	if (c_book->entry_page == NULL)
	{
		c_book->len_line = gen_page(&c_book->entry_page, fd);
		if (c_book->len_line < 1)
			return (NULL);
		c_book->entry_cursor = c_book->entry_page->content;
	}
	size_t next_line = read_book(c_book->entry_page, c_book->entry_cursor, &c_book->len_line, fd);
	out = gen_out(&c_book->entry_page, &c_book->entry_cursor, c_book->len_line - next_line);
	c_book->len_line = next_line;
	return (out);
}