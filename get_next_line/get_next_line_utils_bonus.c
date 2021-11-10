#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>

void free_page(t_page *page)
{
	if (page == NULL)
		return ;
	free(page->content);
	free(page);
}

char * ft_strchr(const char *src, const char c)
{
	while (*src)
	{
		if (*src == c)
			return (char *) src;
		++src;
	}
	return (NULL);
}

t_page *gen_empty_page()
{
	t_page *page;

	page = malloc(sizeof(t_page));
	if (page == NULL)
		return NULL;
	page->content = (char *) malloc(BUFFER_SIZE + 1);
	if (page->content == NULL)
	{
		free(page);
		return NULL;
	}
	page->content[BUFFER_SIZE] = 0;
	page->next = NULL;
	return (page);
}

ssize_t gen_page(t_page **page, const int fd)
{
	ssize_t readed_bytes;

	*page = gen_empty_page();
	
	if (*page == NULL)
		return (0);
	readed_bytes = read(fd, (*page)->content, BUFFER_SIZE);
	if (readed_bytes < 1)
	{
		free_page(*page);
		*page = NULL;
	}
	else
		(*page)->content[readed_bytes] = 0;
	return (readed_bytes);
}

size_t	read_book(t_page *page, char *cursor, ssize_t *len_line, const int fd)
{
	char		*n_pos;
	ssize_t	readed_bytes;

	readed_bytes = *len_line;
	while (1)
	{
		n_pos = ft_strchr(cursor, '\n');
		if (n_pos != NULL)
			return readed_bytes - (n_pos - cursor + 1);
		readed_bytes = gen_page(&page->next, fd);
		if (readed_bytes < 1)
			break ;
		*len_line += readed_bytes;
		page = page->next;
		cursor = page->content;
	}
	return (0);
}