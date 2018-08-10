/*
** getnbr.c for  in /home/zegher_a/Modules/Infographie/gfx_incendie
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Sun Dec  6 22:45:54 2015 alexis zeghers
** Last update Fri Feb 19 18:18:31 2016 alexis zeghers
*/

#include "include/allum.h"

int	getnbr(const char *str)
{
  int	nbr;
  int	i;

  i = 0;
  nbr = 0;
  if (str[0] > '9' || str[0] < '0')
    {
      write(1, "Error: invalid input (positive number expected)\n", 48);
      return (-1);
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr + (str[i] - '0');
      i = i + 1;
    }
  if ((str[i] != '\n' && str[i] != 0) || nbr < 0)
    {
      write(1, "Error: invalid input (positive number expected)\n", 48);
      return (-1);
    }
  return (nbr);
}
