#include <stdlib.h>
#include <sys/types.h>
#include "get_next_line_bonus.h"
#include <stdio.h>

static t_book *create_book(const int fd)
{
	t_book *book;

	book = (t_book *) malloc(sizeof(t_book));
	if (book == NULL)
		return (NULL);
	book->fd = fd;
	book->buf[0] = 0;
	book->next = NULL;
	return (book);
}

static t_book *get_fd_book(t_book **book, const int fd)
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

static void fill_buff(char *buf, char *cursor)
{
	size_t i;

	i = 0;
	while(cursor && cursor[i])
	{
		buf[i] = cursor[i];
		++i;
	}
	buf[i] = 0;
}

static char *gen_out(char *buf, t_page *entry_page, size_t out_size)
{
	char		*cursor_page;
	char		*out;
	size_t	i;

	if (out_size < 1)
		return (NULL);
	out = malloc(out_size + 1);
	if (out == NULL)
		return (NULL);
	out[out_size] = 0;
	i = 0;
	while (buf[i] && i < out_size)
	{
		out[i] = buf[i];
		++i;
	}
	if (entry_page)
	{
		cursor_page = cpyn_book(out + i, out_size - i, &entry_page);
		fill_buff(buf, cursor_page);
		free(entry_page);
	}
	else
		fill_buff(buf, buf + i);
	return (out);
}

char	*get_next_line(int fd)
{
	static t_book *entry_book = NULL;
	t_page				*entry_page;
	char					*buf_cursor;
	t_book				*book; 

	if (fd < 0)
		return (NULL);
	entry_page = NULL;
	book = get_fd_book(&entry_book, fd);
	if (book == NULL)
		return NULL;
	buf_cursor = ft_strchr(book->buf, '\n');
	if (*buf_cursor != '\n')
		return gen_out(book->buf, entry_page, (buf_cursor - book->buf) + read_book(&entry_page, fd));
	else if(*buf_cursor)
		return gen_out(book->buf, entry_page, buf_cursor - book->buf + 1);
	else
		return (NULL);
}

/*
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("./test", O_RDONLY);

	char *s;
	s = get_next_line(fd);
	while(s)
	{
		printf("%s", s);
		s = get_next_line(fd);
	}
	return 0;
}
*/