void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *prev;
    t_list *current;

    if (!begin_list || !*begin_list)
        return ;
    current = *begin_list;
    prev = NULL;
    while (current)
    {
        if (cmp(current -> data, data_ref) == 0)
        {
            if (current == *begin_list)
            {
                *begin_list = current -> next;
                free(current);
                current = *begin_list;
            }
            else
            {
                prev -> next = current -> next;
                free(current);
                current = prev -> next;
            }
        }
        else
        {
            prev = current;
            current = current -> next;
        }
    }
}
