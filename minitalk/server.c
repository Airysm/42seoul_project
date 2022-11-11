/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:31:11 by dseo              #+#    #+#             */
/*   Updated: 2022/09/27 19:06:51 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_siginfo	g_siginfo;

void	siginfo_init(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_siginfo.signal_str[i] = '0';
		i++;
	}
	g_siginfo.signal_str[i] = '\0';
	g_siginfo.index = 0;
}

void	signal_to_int(char *signal_str)
{
	int	digit;
	int	ascii_num;
	int	count;

	digit = 0;
	ascii_num = 0;
	count = 0;
	while (digit <= 6)
	{
		if (signal_str[digit] == '1')
		{
			ascii_num += 1 << (6 - digit);
			count++;
		}
		digit++;
	}
	if (count % 2 != signal_str[digit] - '0')
	{
		ft_printf("parity bit error");
		exit(1);
	}
	if (ascii_num == 0)
		ft_printf("\n");
	ft_printf("%c", (char)ascii_num);
}

void	action(int signo)
{
	if (signo == SIGUSR1)
	{
		g_siginfo.signal_str[g_siginfo.index] = '1';
		g_siginfo.index += 1;
	}
	else if (signo == SIGUSR2)
	{
		g_siginfo.signal_str[g_siginfo.index] = '0';
		g_siginfo.index += 1;
	}
	if (g_siginfo.index == 8)
	{
		signal_to_int(g_siginfo.signal_str);
		siginfo_init();
	}
}

int	main(void)
{
	struct sigaction	act;

	siginfo_init();
	ft_printf("Server PID : %d\n", getpid());
	act.sa_handler = action;
	act.sa_flags = 0;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		ft_printf ("signal(SIGUSR1) error");
		exit(1);
	}
	if (sigaction(SIGUSR2, &act, NULL) == -1)
	{
		ft_printf ("signal(SIGUSR2) error");
		exit(1);
	}
	while (1)
		;
	return (0);
}
