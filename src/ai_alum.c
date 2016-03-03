/*
** ai_alum.c for allum1 in /home/clemen_j/Work/CPE/CPE_2015_Allum1/src
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Thu Feb 18 10:46:37 2016 Clémenceau Cedric
** Last update Wed Feb 24 19:09:42 2016 Clémenceau Cedric
*/

#include "struct.h"

int	somme_nim(char **str)
{
  int	i;
  int	j;
  int	matches_ligne;
  int	nbr_somme;

  matches_ligne = 0;
  i = 0;
  nbr_somme = 0;
  while (str[++i])
    {
      j = 0;
      matches_ligne = 0;
      while (str[i][++j])
	{
	  if (str[i][j] == '|')
	    matches_ligne++;
	}
      nbr_somme = matches_ligne ^ nbr_somme;
    }
  return (nbr_somme);
}

void	my_rand(int *tmp, int *line, t_info *data)
{
  int	i;
  int	matches_ligne;

  i = 0;
  while (data->aff_map[i])
    {
      *line = rand() % 4;
      if ((matches_ligne = calcul_someth(data->aff_map[*line], '|')) == 0)
	i++;
      else
	break ;
    }
  *tmp = 1;
}

int	ia_xor(t_info *data)
{
  int	somme;
  int	i;
  int	tmp;
  int	matches_ligne;
  int	line;

  i = 0;
  my_putstr("\nAI's turn...\n");
  somme = somme_nim(data->aff_map) ^ 1;
  while (data->aff_map[++i] && i < 5 && somme != 0)
    {
      matches_ligne = calcul_someth(data->aff_map[i], '|');
      if (matches_ligne > (somme ^ matches_ligne))
	{
	  line = i;
	  tmp = somme ^ matches_ligne;
	  break ;
	}
    }
  if (tmp == 0 || somme == 0)
    my_rand(&tmp, &line, data);
  my_ia_putline(line, tmp);
  if (tmp <= matches_ligne && (remove_matches(line, tmp, data, 1)) == - 1)
    return (-1);
  return (0);
}
