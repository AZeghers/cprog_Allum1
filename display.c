/*
** display.c for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_Allum1
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Thu Feb 18 15:37:32 2016 alexis zeghers
** Last update Thu Feb 18 15:52:30 2016 alexis zeghers
*/

#include "include/allum.h"

void	put_nbr(int nb)
{
  char	c;

  if (nb >= 10)
    put_nbr(nb / 10);
  c = nb % 10 + '0';
  write(1, &c, 1);
}

void	next_display(t_match alu, int n, int i)
{
  while (++i < 4)
    {
      write(1, "*", 1);
      n = -1;
      while (++n < (3 - i))
	write(1, " ", 1);
      n = -1;
      while (++n < alu.line[i])
	write(1, "|", 1);
      n = -1;
      while (++n < alu.sp[i])
	write(1, " ", 1);
      write(1, "*\n", 2);
    }
}

void	display(t_match alu)
{
  int	n;
  int	i;

  i = -1;
  n = -1;
  write(1, "*********\n", 10);
  next_display(alu, n, i);
  write(1, "*********\n", 10);
}
