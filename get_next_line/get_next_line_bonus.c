#include <stdlib.h>
#include <sys/types.h>
#include "get_next_line_bonus.h"

t_book *create_book(const int fd)
{
	t_book *book;

	book = (t_book *) malloc(sizeof(t_book));
	if (book == NULL)
		return (NULL);
	book->fd = fd;
	book->entry_page = NULL;
	book->entry_cursor = NULL;
	book->len_line = 0;
	book->next = NULL;
	return (book);
}

t_book *get_fd_book(t_book **book, const int fd)
{
	while (*book)
	{
		if ((*book)->fd == fd)
			return (*book);
		book = &(*book)->next;
	}
	*book = create_book(fd);
	return (*book);
}

char get_next_c_book(t_page **page, char **cursor)
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
	static t_book *entry_book = NULL;
	char					*out;
	t_book				*c_book;
	size_t				next_line;

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
	next_line = read_book(c_book->entry_page, c_book->entry_cursor, &c_book->len_line, fd);
	out = gen_out(&c_book->entry_page, &c_book->entry_cursor, c_book->len_line - next_line);
	c_book->len_line = next_line;
	return (out);
}