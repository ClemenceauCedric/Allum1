/*
** error_alum.c for allum1 in /home/clemen_j/Work/CPE/CPE_2015_Allum1
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Tue Feb 16 16:05:03 2016 Clémenceau Cedric
** Last update Wed Feb 24 19:08:25 2016 Clémenceau Cedric
*/

#include "struct.h"

int	write_nbr(char *str, int *i, char *av)
{
  my_putstr(str);
  if (((*i) = my_getnbr(get_next_line(0), 1)) < 0)
    {
      if (*i == -10)
	return (my_putstr("\n"), -1);
      my_putstr("Error: invalid input (positive number expected)\n");
      write_nbr(str, i, av);
    }
  else if ((*i) == 0 || (*i) > my_getnbr(av, 0))
    {
      my_putstr("Error: this line is out of range\n");
      write_nbr(str, i, av);
    }
  return (0);
}

int	write_nbr_matches(char *str, int *j, char *av, char *line)
{
  int	matches;

  matches = calcul_someth(line, '|');
  if (matches == 0)
    return (my_putstr("Error: this line is empty\n"), -1);
  my_putstr(str);
  if ((*j = my_getnbr(get_next_line(0), 1)) < 0 || av[0] == '\n')
    {
      if (*j == -10)
	return (my_putstr("\n"), -2);
      return (my_putstr("Error: invalid input (positive number expected)\n"), -1);
    }
  else  if (*j > ((my_getnbr(av, 0) * 2) - 1) || *j > matches)
    return (my_putstr("Error: not enough matches on this line\n"), -1);
  else if (*j == 0)
    return (my_putstr("Error: you have to remove at least one match\n"), -1);
  return (1);
}

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  write(1, str, i);
}
