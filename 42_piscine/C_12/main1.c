#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = (t_list *)malloc(sizeof(t_list));
	list -> next = 0;
	list -> data = data;
	return (list);
}

void	ft_swap_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *current;
	t_list *next;
	bool	swapped;

	if (lst == 0)
		return (0);
	swapped = true;
	while (swapped)
	{
		swapped = false;
		current = lst;
		while (current)
		{
			next = current->next;
			if (next != 0 && (*cmp)(current->data, next->data) == 0)
			{
				ft_swap_int(&(current->data), &(next->data));
				swapped = true;
			}
			current = next;
		}
	}
	return (lst);
}


int main()
{
	int a = 10;
	int *ptr = &a;
	t_list *lst;
	

	lst = ft_create_elem(&a);


	printf("%d", &(lst->data));
}
