/*
** stuct.h for allum1 in /home/clemen_j/Work/CPE/CPE_2015_Allum1
**
** Made by Clémenceau Cedric
** Login   <clemen_j@epitech.net>
**
** Started on  Wed Feb 10 10:56:28 2016 Clémenceau Cedric
** Last update Sun Feb 21 19:46:52 2016 Clémenceau Cedric
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# include <get_next_line.h>

	/* IA's fonctions */
int	ia_xor(t_info *);

	/* Others Fonctions */
int	my_getnbr(char *, int);
int	my_strlen(char *);
char	*get_next_line(const int);

	/* Free a gogo */
void	my_freebox(t_info *, int);

	/* calculated */
int	count_matches(char **);
int	my_strlen(char *);
int	calcul_someth(char *, char);
int	calcul_spaces_after(char *, char, char);
int	remove_matches(int, int, t_info *, int);
int	write_nbr(char *, int *, char *);
int	write_nbr_matches(char *, int *, char *, char *);

	/* Display me ... */
void	print_game_board(t_info *, int);
void	my_show_game(t_info *);
void	my_putline(int, int);
void	my_ia_putline(int, int);
void	my_putstr(char *);
void	my_put_nbr(int);

#endif /* !STRUCT_H_ */
