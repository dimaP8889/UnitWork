#include "header.h"

void	free_mem(t_list *list)
{
	int		index;

	index = 0;
	free(list->str);
	while (list->include[index])
	{
		free(list->include[index]);
		index++;
	}
}

void	ft_clean(t_list **list)
{
	t_list *clean;

	clean = *list;
	while (clean)
	{
		free_mem(clean);
		free(clean->include);
		clean = clean->next;
	}
}
