/*
** aff_alum.c for allum1 in /home/clemen_j/Work/CPE/CPE_2015_Allum1
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Mon Feb 15 19:09:25 2016 Clémenceau Cedric
** Last update Wed Feb 24 18:51:23 2016 Clémenceau Cedric
*/

#include "struct.h"

void	my_putline(int i, int j)
{
  my_putstr("Player removed ");
  my_put_nbr(j);
  my_putstr(" match(es) from line ");
  my_put_nbr(i);
  write(1, "\n", 1);
}

void	my_ia_putline(int line, int matches)
{
  my_putstr("AI removed ");
  my_put_nbr(matches);
  my_putstr(" match(es) from line ");
  my_put_nbr(line);
  write(1, "\n", 1);
}

void	my_show_game(t_info *data)
{
  int	i;
  int	j;

  i = 0;
  j = -1;
  while (data->aff_map[++j]);
  while (i < j)
    {
      my_putstr(data->aff_map[i]);
      write(1, "\n", 1);
      i++;
    }
}

int	count_matches(char **map)
{
  int	i;
  int	j;
  int	z;

  i = 0;
  z = 0;
  while (map[i])
    {
      j = 0;
      while (map[i][j])
	{
	  if (map[i][j] == '|')
	    z++;
	  j++;
	}
      i++;
    }
  return (z);
}

void	print_game_board(t_info *data, int nb)
{
  int	i;
  int	j;

  i = -1;
  if ((data->aff_map = malloc(sizeof(char *) *(nb + 3))) == NULL)
    return ;
  data->aff_map[nb + 2] = NULL;
  while (++i != nb + 2)
    {
      j = 0;
      if ((data->aff_map[i] = malloc((nb *2) + 2)) == NULL)
	return ;
      data->aff_map[i][(nb * 2) + 1] = 0;
      while(j != (nb * 2) + 1)
	{
	  if (i == 0 || j == 0 || i == nb + 1 || j == nb * 2)
	    data->aff_map[i][j] = '*';
	  else if (j > nb - i && j < nb * 2 - (nb - i))
	    data->aff_map[i][j] = '|';
	  else
	    data->aff_map[i][j] = ' ';
	  write(1, &data->aff_map[i][j++], 1);
	}
      write(1, "\n", 1);
    }
}
