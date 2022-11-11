/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 05:36:23 by dseo              #+#    #+#             */
/*   Updated: 2022/09/25 06:03:35 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include "./ft_printf/ft_printf.h"

typedef struct signal_information
{
	char	signal_str[8];
	int		index;
}	t_siginfo;

#endif
