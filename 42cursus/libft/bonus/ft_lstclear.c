#include <stdlib.h>
#include <libft.h>

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	if((*lst)->next)
		ft_lstclear(lst, del);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}