/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:52:40 by dseo              #+#    #+#             */
/*   Updated: 2022/01/27 10:29:13 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_print_memory(void *abbr, unsigned int size);

void	*ft_print_memory(void *abbr, unsigned int size)
{
	void			*pptr;
	unsigned int	i;

	i = 0;
	*ptr = &abbr[0];
	while (i < 16)
	{
		pptr = &ptr + '0';
		write(1, &pptr, 1);
		i++;
	}
	return (abbr);
}
