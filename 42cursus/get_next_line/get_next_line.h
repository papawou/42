#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_page
{
	char					*content;
	struct s_page	*next;
} t_page;

/*
typedef struct s_bibl
{
	int						fd;
	t_page				*entry_page;
	t_page				*cursor_page;
	char					*cursor;
	size_t				len_line;
	struct s_bibl *next;
}	t_bibl;
*/
void		free_pages(t_page *page);
char		*get_next_line(int fd);
size_t	read_book(t_page *page, char *cursor, size_t *len_line, const int fd);
char		get_next_c_book(t_page **page, char **cursor);
ssize_t gen_page(t_page **page, const int fd);
#endif