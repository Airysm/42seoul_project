/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:11:13 by dseo              #+#    #+#             */
/*   Updated: 2022/01/13 15:16:33 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	hex(char c);

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			hex(str[i]);
		i++;
	}
}

void	hex(char c)
{
	char			a;
	int				div;
	int				mod;
	unsigned char	c_unsign;

	if (c < 0)
		c_unsign = c + 256;
	else
		c_unsign = c;
	div = c_unsign / 16;
	mod = c_unsign % 16;
	write(1, "\\", 1);
	if (div < 10)
		a = div + '0';
	else
		a = div + 'a' - 10;
	write(1, &a, 1);
	if (mod < 10)
		a = mod + '0';
	else
		a = mod + 'a' - 10;
	write(1, &a, 1);
}
