/*
** allum.c for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_Allum1
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Mon Feb  8 11:33:55 2016 alexis zeghers
** Last update Sat Feb 20 01:52:55 2016 alexis zeghers
*/

#include "include/allum.h"

void		init_struct(t_match *alu)
{
  int		i;

  i = -1;
  alu->mtc_nb = 16;
  while (++i < 4)
    alu->sp[i] = 3 - i;
  i = -1;
  while (++i < 4)
    alu->line[i] = i * 2 + 1;
  alu->win = 2;
}

void		win_or_loss(t_match alu)
{
  if (alu.win == 1)
    write(1, "I lost.. snif.. but I'll get you next time!!\n", 45);
  else
    write(1, "You lost, too bad..\n", 20);
}

int		main(void)
{
  t_match	alu;
  int		n;

  init_struct(&alu);
  display(alu);
  write(1, "\nYour turn:\n", 12);
  while (alu.win == 2)
    {
      if ((n = (user_turn(&alu))) == 0)
	{
	  display(alu);
	  if (alu.win == 2)
	    {
	      write(1, "\nAI's turn...\n", 14);
	      ai_turn(&alu);
	      display(alu);
	    }
	  if (alu.win == 2)
	    write(1, "\nYour turn:\n", 12);
	}
      else if (n == -1)
	return (-1);
    }
  win_or_loss(alu);
  return (0);
}
