/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:15:54 by dseo              #+#    #+#             */
/*   Updated: 2022/01/18 12:33:52 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);
int	base_chk(char *base, int bsize);
int	str_to_int(char *str, char *base, int bsize);
int	atoi_base(char *str, int bsize, int i, int it);

int	g_minus;
int	g_result;
int	g_mode;

int	ft_atoi_base(char *str, char *base)
{
	int	bsize;

	bsize = 0;
	g_minus = 1;
	g_result = 0;
	g_mode = 0;
	while (base[bsize] != '\0')
		bsize++;
	if (base_chk(base, bsize))
		return (0);
	return (str_to_int(str, base, bsize));
}

int	base_chk(char *base, int bsize)
{
	int	i;
	int	j;

	if (bsize <= 1)
		return (1);
	i = 0;
	while (i < bsize)
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (1);
		j = i + 1;
		while (j < bsize)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	str_to_int(char *str, char *base, int bsize)
{
	int	i;
	int	j;
	int	it;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		it = -1;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
			{
				it = j;
				break ;
			}
			j++;
		}
		if (atoi_base(str, bsize, i, it))
			break ;
		i++;
	}
	return (g_minus * g_result);
}

int	atoi_base(char *str, int bsize, int i, int it)
{
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{
		if (g_mode > 0)
			return (1);
	}
	else if (str[i] == '+' || str[i] == '-')
	{
		if (g_mode > 1)
			return (1);
		g_mode = 1;
		if (str[i] == '-')
			g_minus = g_minus * -1;
	}
	else if (it != -1)
	{
		g_mode = 2;
		g_result = g_result * bsize + it;
	}
	else
		return (1);
	return (0);
}
