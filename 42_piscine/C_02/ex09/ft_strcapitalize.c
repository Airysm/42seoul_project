/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:24:00 by dseo              #+#    #+#             */
/*   Updated: 2022/01/20 11:14:58 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);
int		compare_str(char c);

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (compare_str(str[0]) == 2)
		str[0] += 'A' - 'a';
	while (str[i + 1] != '\0')
	{
		if (str[0] == '\0')
			break ;
		if ((compare_str(str[i]) == 3) && (compare_str(str[i + 1]) == 2))
			str[i + 1] += 'A' - 'a';
		if ((compare_str(str[i]) == 0) && (compare_str(str[i + 1]) == 1))
			str[i + 1] += 'a' - 'A';
		if ((compare_str(str[i]) == 1) && (compare_str(str[i + 1]) == 1))
			str[i + 1] += 'a' - 'A';
		if ((compare_str(str[i]) == 2) && (compare_str(str[i + 1]) == 1))
			str[i + 1] += 'a' - 'A';
		i++;
	}
	return (str);
}

int	compare_str(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	else if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (2);
	else
		return (3);
}
