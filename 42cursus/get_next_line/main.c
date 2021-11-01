#include <unistd.h>

static BUF_SIZE = 255;

typedef struct s_page
{
	char						content[BUF_SIZE + 1];
	struct	s_page	*next;
} t_page;

typedef struct s_bibl
{
	int						fd;
	t_page				entry_page;
	t_page				cursor_page;
	size_t				cursor;
	size_t				len_line;
	struct s_bibl *next;
}	t_bibl;

t_bibl *gen_new_bibl(const int fd)
{
	t_bibl	*bibl;

	bibl = malloc(sizeof(t_bibl));
	if (!bibl)
		return (NULL);
	bibl->fd = fd;
	bibl->entry_page = NULL;
	bibl->cursor = 0;
	bibl->cursor_page = NULL;
	bibl->len_line = 0;
	bibl->next = NULL;
	return (bibl);
}

t_bibl *get_fd_bibl(t_bibl **bibl, const int fd)
{
	while (*bibl)
	{
		if ((*bibl)->fd == fd)
			return (*bibl);
		bibl = &bibl->next;
	}

	*bibl = gen_new_bibl(fd);
	return (*bibl);
}

t_page *gen_empty_page()
{
	t_page *page;

	page = malloc(sizeof(page));
	if (!page)
		return NULL;
	page->next = NULL;
	page->content[BUF_SIZE] = 0;
	return (page);
}

size_t gen_new_page(t_page **page, const int fd)
{
	*page = gen_empty_page();
	if (*page == NULL)
		return (0);
	return read(fd, page->content, BUF_SIZE);
}

int	fill_bibl(t_bibl *bibl, const int fd)
{
	size_t	bytes_read;
	size_t	n_pos;

	if (bibl->cursor_page == NULL)
	{
		bibl->cursor_page = gen_empty_page();
		bibl->entry_page = bibl->entry_page;
	}
	else
	{
		n_pos = ft_strchr(bibl->cursor_page->content[bibl->cursor], '\n');
		if(n_pos)
			//end
	}
	
	while (bytes_read = read(bibl->fd, bibl->cursor_page->content, BUF_SIZE))
	{
		if (bytes_read == -1) //error
			return -1;
		n_pos = ft_strchr(bibl->cursor_page->content, '\n');
		if (n_pos)
			break ;
		if (bytes_read < BUF_SIZE) //eof
			break ;
		bibl->cursor_page->next = gen_empty_page();
		bibl->cursor_page = bibl->cursor_page->next;
		bibl->len_size += BUF_SIZE;
	}
}

char *get_next_line(int fd)
{
	static t_bibl *bibl = NULL;
	
	t_bibl *fd_bibl = get_fd_bibl(&bibl, fd);
	if (!fd_bibl)
		return (NULL);
}

int main(void)
{
	int fd = open("./txt.txt");
	if (fd < 0)
		return ;
	char *line = get_next_line(fd);
	return 0;
}