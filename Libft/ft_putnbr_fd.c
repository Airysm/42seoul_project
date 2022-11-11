/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:11:33 by dseo              #+#    #+#             */
/*   Updated: 2022/04/28 18:53:07 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (fd < 0)
		return ;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		c = (n % 10) + '0';
		ft_putnbr_fd(n / 10, fd);
		write(fd, &c, 1);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}
