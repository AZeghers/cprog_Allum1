/*
** player.c for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_Allum1
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Thu Feb 18 15:36:16 2016 alexis zeghers
** Last update Sat Feb 20 01:48:36 2016 alexis zeghers
*/

#include "include/allum.h"

int		user_line(t_urn *turn, t_match *alu)
{
  char		*s;

  write(1, "Line: ", 6);
  if ((s = get_next_line(0)) == NULL)
    {
      free(s);
      return (-1);
    }
  turn->line = getnbr(s);
  free(s);
  if (turn->line == -1)
    return (1);
  if (turn->line == 0 || turn->line > 4)
    {
      write(1, "Error: this line is out of range\n", 33);
      return (1);
    }
  if (alu->line[turn->line - 1] == 0)
    {
      write(1, "Error: this line is empty\n", 26);
      return (1);
    }
  return (0);
}

int		user_matches(t_urn *turn, t_match *alu)
{
  char		*s;

  write(1, "Matches: ", 9);
  if ((s = get_next_line(0)) == NULL)
    {
      free(s);
      return (-1);
    }
  turn->mtc_nb = getnbr(s);
  free(s);
  if (turn->mtc_nb == -1)
    return (1);
  if (alu->line[turn->line - 1] < turn->mtc_nb || turn->mtc_nb < 1)
    {
      (turn->mtc_nb < 1) ?
	write(1, "Error: you have to remove at least one match\n", 45) :
	write(1, "Error: not enough matches on this line\n", 39);
      return (1);
    }
  write(1, "Player removed ", 15);
  put_nbr(turn->mtc_nb);
  write(1, " match(es) from line ", 21);
  put_nbr(turn->line);
  write(1, "\n", 1);
  return (0);
}

int		user_turn(t_match *alu)
{
  t_urn		turn;
  int		n;

  if ((n = (user_line(&turn, alu))) != 0)
    return (n);
  if ((n = (user_matches(&turn, alu))) != 0)
    return (n);
  alu->line[turn.line - 1] = alu->line[turn.line - 1] - turn.mtc_nb;
  alu->sp[turn.line - 1] = alu->sp[turn.line - 1] + turn.mtc_nb;
  alu->mtc_nb = alu->mtc_nb - turn.mtc_nb;
  if (alu->mtc_nb == 0)
    ai_wins(alu);
  return (0);
}

void		player_wins(t_match *alu)
{
  int		n;

  n = -1;
  alu->mtc_nb = 0;
  while (++n < 4)
    {
      alu->line[n] = 0;
      alu->sp[n] = 4 + n;
    }
  alu->win = 1;
}
