/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:52:39 by dseo              #+#    #+#             */
/*   Updated: 2022/01/26 14:53:23 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "operator.h"
#include "ft_func.h"

int		calculate(int num1, int num2, char *operator);

int	main(int argc, char **argv)
{
	int	result;
	int	num1;
	int	num2;

	if (argc == 4)
	{
		num1 = ft_atoi(argv[1]);
		num2 = ft_atoi(argv[3]);
		if ((ft_strcmp(argv[2], "/") == 0) && num2 == 0)
			ft_putstr("Stop : division by zero\n");
		else if ((ft_strcmp(argv[2], "%") == 0) && num2 == 0)
			ft_putstr("Stop : modulo by zero\n");
		else
		{
			result = calculate(num1, num2, argv[2]);
			ft_putnbr(result);
			write(1, "\n", 1);
		}
	}
	return (0);
}

int	calculate(int num1, int num2, char *operator)
{
	int	(*f)(int, int);

	if (ft_strcmp(operator, "+") == 0)
		f = ft_sum;
	else if (ft_strcmp(operator, "-") == 0)
		f = ft_minus;
	else if (ft_strcmp(operator, "*") == 0)
		f = ft_mul;
	else if (ft_strcmp(operator, "/") == 0)
		f = ft_div;
	else if (ft_strcmp(operator, "%") == 0)
		f = ft_mod;
	else
		return (0);
	return (f(num1, num2));
}
