/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:47:17 by dseo              #+#    #+#             */
/*   Updated: 2022/01/08 09:56:33 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

void	ft_print_reverse_alphabet(void)
{
	char	alphabet_rev;

	alphabet_rev = 122;
	while (alphabet_rev >= 97)
	{
		write(1, &alphabet_rev, 1);
		alphabet_rev--;
	}
}
