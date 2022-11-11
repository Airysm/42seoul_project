/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:29:00 by dseo              #+#    #+#             */
/*   Updated: 2022/01/27 13:39:39 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_print(char *filename);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		ft_print(argv[1]);
	}
	return (0);
}

void	ft_print(char *filename)
{
	char	read_buf[1024];
	int		fd;
	int		n;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	n = read(fd, read_buf, 1024);
	ft_putstr(read_buf);
	close(fd);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
