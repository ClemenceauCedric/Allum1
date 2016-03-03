/*
1;2802;0c** put_nbrs.c for minitalk in /home/clemen_j/Work/PSU/PSU_2015_minitalk/src_server
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Wed Feb 10 01:15:41 2016 Clémenceau Cedric
** Last update Wed Feb 24 19:10:51 2016 Clémenceau Cedric
*/

#include <struct.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    i++;
  return (i);
}

void	my_put_nbr(int nb)
{
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
}
