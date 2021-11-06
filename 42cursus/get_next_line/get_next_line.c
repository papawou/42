#include <stdlib.h>
#include "get_next_line.h"

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
	static int 		_fd = -1;
	static t_page *entry_page = NULL;
	static char   *entry_cursor = NULL;
	static ssize_t len_line = 0;
	char *out;

	if (_fd != fd)
	{
		_fd = fd;
		free_pages(entry_page);
		entry_page = NULL;
		entry_cursor = NULL;
	}

	if (entry_page == NULL)
	{
		len_line = gen_page(&entry_page, fd);
		if (len_line < 1)
			return (NULL);
		entry_cursor = entry_page->content;
	}
	
	size_t next_line = read_book(entry_page, entry_cursor, &len_line, fd);
	out = gen_out(&entry_page, &entry_cursor, len_line - next_line);
	len_line = next_line;
	return (out);
}

/*
#include <fcntl.h>
#include <stdio.h>


int main(void)
{
	int fd = open("./txt.txt", O_RDONLY);
	if (fd < 0)
		return 0 ;
	char *line = get_next_line(fd);
		
	while(line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	get_next_line(-2);
	return 0;
}
*/