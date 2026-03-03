#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;
	t_list	*current;
	t_list	*prev;

	temp = NULL;
	prev = NULL;
	current = *begin_list;
	if (!begin_list || !*begin_list)
		return;
	while (current)
	{
		if (cmp(current -> data, data_ref) == 0)
		{
			if (!prev)//es el primer nodo
			{
				*begin_list = current -> next;
				temp = current;
				current = current -> next;
				free(temp);
			}
			else
			{
				temp = current;
				prev -> next = current -> next;
				current = current -> next;
				free(temp);
			}
		}
		else
		{
			prev = current;
			current = current -> next;
		}
	}
}

