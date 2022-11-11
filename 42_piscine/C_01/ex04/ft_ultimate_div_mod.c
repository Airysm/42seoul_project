/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:12:03 by dseo              #+#    #+#             */
/*   Updated: 2022/01/10 20:49:12 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	value_a;
	int	value_b;

	value_a = *a;
	value_b = *b;
	if ((value_a == -2147483648 && value_b == -1) || value_b == 0)
		return ;
	*a = value_a / value_b;
	*b = value_a % value_b;
}
