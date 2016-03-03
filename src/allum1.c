/*
** allum1.c for allum1 in /home/clemen_j/Work/CPE/CPE_2015_Allum1
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Wed Feb 10 10:49:56 2016 Clémenceau Cedric
** Last update Wed Feb 24 18:19:01 2016 Clémenceau Cedric
*/

#include "struct.h"

int	rm_matches(t_info *data, int i, int j, int matches_max)
{
  my_putline(i, j);
  if ((remove_matches(i, j, data, 0)) == -1)
    return (-1);
  my_show_game(data);
  if (matches_max > 1)
    if ((ia_xor(data)) == -1)
      return (-1);
  my_show_game(data);
  return (0);
}

int	checkit(int z, int *i, char *av)
{
  z = write_nbr("Line: ", i, av);
  if (z == -2)
    return (-1);
  return (z);
}

int	play_game(int i, char *av, t_info *data)
{
  int	z;
  int	j;
  int	matches_max;

  z = -1;
  j = 0;
  matches_max = count_matches(data->aff_map);
  my_putstr("\nYour turn:\n");
  while(++z != 3)
    {
      if (z == 0)
	{
	  if ((z = checkit(z, &i, av)) == -1)
	    return (-1);
	}
      else if (z == 1)
	{
	  if ((z = write_nbr_matches("Matches: ", &j, av, data->aff_map[i])) == -2)
	    return (-1);
	}
      else
	if ((rm_matches(data, i, j, matches_max)) == -1)
	    return (-1);
    }
  return (0);
}

void	my_freebox(t_info *data, int nb)
{
  int	i;

  i = 0;
  while (i != (nb + 2))
    {
      free(data->aff_map[i]);
      i++;
    }
  free(data->aff_map);
}

int		main(int ac, char **av)
{
  t_info	data;
  int		i;

  if (ac > 2)
    return (-1);
  if (ac == 1)
    av[1] = "4";
  data.nbr = my_getnbr(av[1], 0);
  if ((i = my_getnbr(av[1], 0)) == -1 || i < 2 || i > 300)
    {
      my_putstr("too much / too few arguments, or invalide input\n");
      return (-1);
    }
  print_game_board(&data, i);
  i = 0;
  while (42)
    if ((play_game(i, av[1], &data)) == -1)
      return (-1);
  return (0);
}
