/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:31:04 by dseo              #+#    #+#             */
/*   Updated: 2022/09/27 19:22:51 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else if (bit == 0)
		kill(pid, SIGUSR2);
	usleep(50);
}

void	send_char(int pid, int num)
{
	int	digit;
	int	bit;
	int	count;

	digit = 6;
	bit = 0;
	count = 0;
	while (digit >= 0)
	{
		bit = num >> digit & 1;
		if (bit == 1)
			count++;
		send_signal(pid, bit);
		digit--;
	}
	if (count % 2)
		send_signal(pid, 1);
	else
		send_signal(pid, 0);
}

void	send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(pid, (int)str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	ft_atoi(const char *str)
{
	int		result;
	int		minus;
	size_t	i;

	i = 0;
	result = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		minus *= -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (minus * result);
}

int	main(int argc, char *argv[])
{
	int	pid_num;

	if (argc != 3)
	{
		ft_printf("incorrect argument");
		exit(1);
	}
	pid_num = ft_atoi(argv[1]);
	if (pid_num <= 0 || pid_num > 99999)
	{
		ft_printf("pid error");
		exit(1);
	}
	ft_printf ("Server PID : %s\nMessage : %s\n", argv[1], argv[2]);
	send_str(pid_num, argv[2]);
	return (0);
}
