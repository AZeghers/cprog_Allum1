/*
** getnbr.c for  in /home/zegher_a/Modules/Infographie/gfx_incendie
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Sun Dec  6 22:45:54 2015 alexis zeghers
** Last update Fri Feb 19 20:12:05 2016 alexis zeghers
*/

#include "include/allum.h"

int	alt_getnbr(const char *str)
{
  int	nbr;
  int	neg;
  int	i;

  neg = 1;
  i = 0;
  nbr = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
	neg = -neg;
      ++i;
    }
  while (str[i] >= '0' && str[i] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr + (str[i] - '0');
      i = i + 1;
    }
  return (nbr * neg);
}

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
