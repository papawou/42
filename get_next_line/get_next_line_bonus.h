#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <sys/types.h>

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

char		*get_next_line(int fd);
size_t	read_book(t_page *page, char *cursor, ssize_t *len_line, const int fd);
ssize_t gen_page(t_page **page, const int fd);
void		free_page(t_page *page);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif

#endif