/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:54:07 by dseo              #+#    #+#             */
/*   Updated: 2022/01/19 16:23:14 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	count;
	int	i;

	if (nb <= 2)
		return (2);
	while (nb <= 2147483647)
	{
		count = 0;
		i = 2;
		while (i <= nb / i)
		{
			if (nb % i == 0)
				count++;
			if (count > 0)
				break ;
			i++;
		}
		if (count == 0)
			break ;
		nb++;
	}
	return (nb);
}
