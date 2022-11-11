/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:19:29 by dseo              #+#    #+#             */
/*   Updated: 2022/01/18 11:07:57 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);
int	str_to_int(char *str, int result, int minus, int i);

int	g_mode;

int	ft_atoi(char *str)
{
	int	result;
	int	minus;
	int	i;

	result = 0;
	minus = 1;
	i = 0;
	g_mode = 0;
	return (str_to_int(str, result, minus, i));
}

int	str_to_int(char *str, int result, int minus, int i)
{
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		{
			if (g_mode > 0)
				break ;
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			if (g_mode > 1)
				break ;
			g_mode = 1;
			if (str[i] == '-')
				minus = minus * -1;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			g_mode = 2;
			result = result * 10 + str[i] - '0';
		}
		else
			break ;
		i++;
	}
	return (minus * result);
}
