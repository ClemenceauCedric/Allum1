/*
** calcul_alum.c for allum1 in /home/clemen_j/Work/CPE/CPE_2015_Allum1
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Tue Feb 16 16:04:14 2016 Clémenceau Cedric
** Last update Wed Feb 24 19:12:30 2016 Clémenceau Cedric
*/

#include "struct.h"

int	calcul_someth(char *str, char c)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (!str)
    return (0);
  while (str[i])
    {
      if (str[i] == c)
	j++;
      i++;
    }
  return (j);
}

int	calcul_spaces_after(char *str, char c, char c2)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (str[++i] != c);
  while (str[i])
    {
      if (str[i] == c2)
	j++;
      i++;
    }
  return (j);
}

int	end_matches(t_info *data, int ia, int line)
{
  my_show_game(data);
  if (ia == 1)
    my_putstr("I lost.. snif.. but I'll get you next time!!\n");
  else
    my_putstr("You lost, too bad..\n");
  my_freebox(data, line);
  return (0);
}

int	remove_matches(int line, int j, t_info *data, int ia)
{
  int	spaces;
  int	i;
  int	nbr_max;
  int	matches_max;

  i = 0;
  spaces = calcul_spaces_after(data->aff_map[line], '|', ' ');
  nbr_max = my_strlen(data->aff_map[line]) - 2;
  while (i < j && matches_max != 0)
    {
      data->aff_map[line][nbr_max - spaces - i] = ' ';
      matches_max = count_matches(data->aff_map);
      i++;
    }
  if (matches_max == 0)
    {
      end_matches(data, ia, line);
      return (-1);
    }
  return (0);
}
