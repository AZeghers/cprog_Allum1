/*
** allum.c for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_Allum1
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Mon Feb  8 11:33:55 2016 alexis zeghers
** Last update Sat Feb 20 01:54:12 2016 alexis zeghers
*/

#include "include/allum.h"

void		free_struct(t_match alu)
{
  free(alu.sp);
  free(alu.line);
}

int		init_struct(t_match *alu, int height)
{
  int		i;

  if (height < 1)
    {
      write(1, "Not enough matches\n", 19);
      return (1);
    }
  i = -1;
  alu->mtc_nb = height * height;
  if ((alu->sp = malloc(sizeof(int) * height)) == NULL)
    return (1);
  alu->height = height;
  while (++i < height)
    alu->sp[i] = height - 1 - i;
  if ((alu->line = malloc(sizeof(int) * height)) == NULL)
    return (1);
  i = -1;
  while (++i < height)
    alu->line[i] = i * 2 + 1;
  alu->win = 2;
  return (0);
}

void		win_or_loss(t_match alu)
{
  if (alu.win == 1)
    write(1, "I lost.. snif.. but I'll get you next time!!\n", 45);
  else
    write(1, "You lost, too bad..\n", 20);
}

int		gameloop(t_match *alu)
{
  int		n;

  while (alu->win == 2)
    {
      if ((n = (user_turn(alu))) == 0)
	{
	  display(*alu);
	  if (alu->win == 2)
	    {
	      write(1, "\nAI's turn...\n", 14);
	      ai_turn(alu);
	      display(*alu);
	    }
	  if (alu->win == 2)
	    write(1, "\nYour turn:\n", 12);
	}
      else if (n == -1)
	return (-1);
    }
  return (0);
}

int		main(int argc, char **argv)
{
  t_match	alu;

  if ((init_struct(&alu, (argc == 1 ? (4) : (alt_getnbr(argv[1]))))) == 1)
    return (-1);
  display(alu);
  write(1, "\nYour turn:\n", 12);
  if ((gameloop(&alu)) == -1)
    return (-1);
  win_or_loss(alu);
  free_struct(alu);
  return (0);
}
