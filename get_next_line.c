/*
** get_next_line.c for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_getnextline
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Mon Jan  4 14:11:47 2016 alexis zeghers
** Last update Fri Feb 19 19:09:14 2016 alexis zeghers
*/

#include "include/allum.h"

int		length(char *s)
{
  int		i;

  i = 0;
  while (s[i])
    ++i;
  return (i);
}

char		*do_realloc(char *s)
{
  char		*tmp;
  int		i;

  i = -1;
  if ((tmp = malloc(length(s) + 1)) == NULL)
    return (NULL);
  while (s[++i])
    tmp[i] = s[i];
  free(s);
  return (tmp);
}

char		*get_next_line(const int fd)
{
  char		*line;
  int		i;
  int		tmp;

  i = 0;
  if ((line = malloc(1)) == NULL)
    return (NULL);
  while (1)
    {
      if (((tmp = (read(fd, &line[i], 1))) == -1) || tmp == 0)
	return (NULL);
      if (line[i] == '\n')
	return (line);
      else
	if ((line = do_realloc(line)) == NULL)
	  return (NULL);
      ++i;
    }
  return (line);
}
