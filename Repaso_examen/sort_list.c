t_list  *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *head;
    int temp;

    head = lst;
    if (!lst)
        return (lst);
    while (lst -> next)
    {
        if (cmp(lst -> data, lst -> next -> data) == 0)
        {
            temp = lst -> data;
            lst -> data = lst -> next -> data;
            lst -> next -> data = temp;
            lst = head;
        }
        else
            lst = lst -> next;
    }
    lst = head;
    return (lst);
}
