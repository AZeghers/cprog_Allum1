/*
** allum.h for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_Allum1/include
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Mon Feb  8 11:17:52 2016 alexis zeghers
** Last update Fri Feb 19 20:13:09 2016 alexis zeghers
*/

#ifndef ALLUM_H_
# define ALLUM_H_

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_match
{
  int		height;
  int		mtc_nb;
  int		*sp;
  int		*line;
  int		win;
}		t_match;

typedef struct	s_urn
{
  int		line;
  int		mtc_nb;
}		t_urn;

/*
** Get Values
*/
char		*get_next_line(const int fd);
int		alt_getnbr(const char *str);
int		getnbr(const char *str);

/*
** Artificial Intelligence (Relative Intelligence)
*/
int		ai_modif(t_match *alu, int n, int mtc);
void		ai_turn(t_match *alu);
void		ai_choice(int n, int mtc);
void		ai_wins(t_match *alu);

/*
** Player Interactions
*/
int		user_line(t_urn *turn, t_match *alu);
int		user_matches(t_urn *turn, t_match *alu);
int		user_turn(t_match *alu);
void		player_wins(t_match *alu);

/*
** Display
*/
void		put_nbr(int nb);
void		next_display(t_match alu, int n, int i);
void		display(t_match alu);

#endif /* !ALLUM_H_ */
