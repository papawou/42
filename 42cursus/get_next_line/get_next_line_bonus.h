#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>

typedef struct s_page
{
	char					*content;
	struct s_page	*next;
} t_page;

typedef struct s_book
{
	int						fd;
	t_page				*entry_page;
	char					*entry_cursor;
	ssize_t				len_line;
	struct s_book *next;
}	t_book;

void		free_pages(t_page *page);
char		*get_next_line(int fd);
size_t	read_book(t_page *page, char *cursor, ssize_t *len_line, const int fd);
char		get_next_c_book(t_page **page, char **cursor);
ssize_t gen_page(t_page **page, const int fd);
void		free_page(t_page *page);

t_book *create_book(const int fd);
t_book *get_fd_book(t_book **book, const int fd);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

#endif