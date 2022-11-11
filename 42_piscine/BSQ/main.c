#include <stdio.h>
#include <unistd.h>

void	make_square(char **map, int n);
int		promise(char **map, int i);

int main()
{
	char	map[100][100];
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			map[i][j] = '.';	
			j++;
		}
		i++;
	}
	map[5][6] = 'o';
	map[2][3] = 'o';

	for (int i= 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
	make_sqare(map, 0);
	return (0);
}

void	make_square(char **map, int n)
{
	int idx = 0;

	if (promise(map, idx - 1))
	{
		if (idx == n)
		{

		}
		else
		{
			make_square(map, idx + 1);
		}
	}
}