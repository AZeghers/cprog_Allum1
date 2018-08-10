/*
** allum.c for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_Allum1
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Mon Feb  8 11:33:55 2016 alexis zeghers
** Last update Mon Feb  8 14:57:07 2016 alexis zeghers
*/

#include "include/allum.h"

void	next_display(int mt, int sp, int n)
{
  while (sp >= 0)
    {
      n = -1;
      write(1, "*", 1);
      while (++n < sp)
	write(1, " ", 1);
      n = -1;
      while (++n < mt)
	write(1, "|", 1);
      n = -1;
      while (++n < sp)
	write(1, " ", 1);
      write(1, "*\n", 2);
      mt = mt + 2;
      --sp;
    }
}

void	init_display(int sp)
{
  int	mt;
  int	n;
  int	st;

  st = (2 * sp) + 3;
  mt = 1;
  n = -1;
  while (++n < st)
    write(1, "*", 1);
  write(1, "\n", 1);
  next_display(mt, sp, n);
  n = -1;
  while (++n < st)
    write(1, "*", 1);
  write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
  int	sp;

  if (argc == 2)
    {
      sp = getnbr(argv[1]) - 1;
      if (sp < 0)
	{
	  write(1, "Not enough matches\n", 18);
	  return (-1);
	}
    }
  else
    sp = 3;
  init_display(sp);
}
