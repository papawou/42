#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

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

void free_pages(t_page *page)
{
	t_page *prev;
	while(page)
	{
		prev = page;
		page = page->next;
		free(prev->content);
		free(prev);
	}
}

t_page *gen_empty_page()
{
	t_page *page;

	page = malloc(sizeof(t_page));
	if (!page)
		return NULL;
	page->content = (char *) malloc(BUFFER_SIZE + 1);
	if (!page->content)
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
		free_pages(*page);
	else
		(*page)->content[readed_bytes] = 0;
	return (readed_bytes);
}

size_t	read_book(t_page *page, char *cursor, size_t *len_line, const int fd)
{
	char		*n_pos;
	size_t	readed_bytes; // -1 from gen_page ?

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

char get_next_c_book(t_page **page, char **cursor)
{
	t_page *tmp_page;
	char c;
	if (**cursor == 0) //eop
	{
		tmp_page = *page;
    *page = (*page)->next; 
		//free prev_page
		free(tmp_page->content);
		free(tmp_page);

		//setup cursor new cursor;
		if (*page)
			*cursor = (*page)->content;
		else //eop_buff should hit ?
			return 0;
	}
	c = **cursor;
	*cursor = *cursor + 1;
	return (c);
}
