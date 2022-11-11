/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_input.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:59:17 by dseo              #+#    #+#             */
/*   Updated: 2022/01/23 16:59:18 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_INPUT_H
# define FT_PRINT_INPUT_H

void	print_level(int size);
int		num_level(char *str);
void	print_3(int num, int size);
void	print_input(char **key, char **value, char *input, int dict_size);

#endif
