#include <stdlib.h>
#include <libft.h>

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *out;

	out = ft_lstnew(f(lst->content));
	if (!out)
		return (NULL);
	if (lst->next)
	{
		out->next = ft_lstmap(lst->next, f, del);
		if (!out->next)
		{
			ft_lstdelone(lst, del);
			return (NULL);
		}
	}
	return (out);
}
