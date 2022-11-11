#include "ft_list.h"

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	void  *temp;
	int i;
	int j;

	i = 0;
	j = 0;
	while (lst[i].next != 0)
	{
		j = i + 1;
		while (lst[j].next != 0)
		{
			if (cmp(lst[i].data, lst[i + 1].data) > 0)
			{
				temp = lst[i].data;
				lst[i].data = lst[i + 1].data;
				lst[i + 1].data = temp;
			}
			j++;
		}
		i++;
	}
	return (lst);
}