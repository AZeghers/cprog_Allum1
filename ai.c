/*
** ai.c for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_Allum1
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Thu Feb 18 15:35:05 2016 alexis zeghers
** Last update Thu Feb 18 15:50:38 2016 alexis zeghers
*/

#include "include/allum.h"

int		ai_modif(t_match *alu, int n, int mtc)
{
  if (alu->line[n] > 1)
    {
      alu->line[n] = mtc - (mtc - 1);
      alu->sp[n] = alu->sp[n] + (mtc - 1);
      alu->mtc_nb = alu->mtc_nb - mtc + 1;
      return (mtc);
    }
  else
    {
      alu->line[n] = 0;
      alu->sp[n] = 4 + n;
      alu->mtc_nb = alu->mtc_nb - 1;
      mtc = 2;
      return (mtc);
    }
}

void		ai_turn(t_match *alu)
{
  int		stop;
  int		n;
  int		mtc;

  n = -1;
  stop = 1;
  while (++n < 4 && stop)
    {
      mtc = alu->line[n];
      if (alu->line[n] > 0)
	{
	  mtc = ai_modif(alu, n, mtc);
	  stop = 0;
	}
    }
  ai_choice(n, mtc);
  if (alu->mtc_nb == 0)
    player_wins(alu);
}

void		ai_choice(int n, int mtc)
{
  write(1, "AI removed ", 11);
  put_nbr(mtc - 1);
  write(1, " match(es) from line ", 21);
  put_nbr(n);
  write(1, "\n", 1);
}

void		ai_wins(t_match *alu)
{
  int		n;

  n = -1;
  alu->mtc_nb = 0;
  while (++n < 4)
    {
      alu->line[n] = 0;
      alu->sp[n] = 4 + n;
    }
  alu->win = 0;
}
