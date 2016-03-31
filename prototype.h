#ifndef _PROTOTYPE_H_
#define  _PROTOTYPE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

typedef struct
{
  int point;
  int bonus;
  int x;
  int y;
} t_play;

typedef struct
{
  int x;
  int y;
  int util;
} t_pos;

void	my_putchar(char c);
void	my_putstr(char *str);
int 	my_strcmp(char *s1, char *s2);
int	my_strlen(char *str);
void	my_put_nbr(int n);
int  	my_getnbr(char *str);
int 	digit(char *str);
char 	*open_map(char *map);
char 	**alloc_tab(char **tab, char *ret, int i);
char 	**tab_map(char *ret);
void 	aff_map(char** tab);
t_play  pos_depart(char** tab, t_play player);
t_pos   pos_arrive(char** tab);
int 	pos(char** map, t_play player);
int     chemin_direct(t_play player, t_pos debut);
int     go_bonus(char **tab, t_play player);
void    search_bonus(char ** tab);
void	start(int argc, char **argv);

#endif
