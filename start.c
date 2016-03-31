#include "prototype.h"

t_play structure(char **argv)
{
  t_play player;
  player.point = my_getnbr(argv[1]);
  player.bonus = my_getnbr(argv[2]);
  return(player);
}

int digit(char *str)
{
  int i;
  
  i = 0;
  while (str[i] != '\0')
    {
      if (!isdigit(str[i]))
	return(0);
      i++;
    }
  return(1);
}

void algo(char **argv, char * ret)
{
  t_play player;
  char **tab;
  int result;
  
  tab = tab_map(ret);
  player = structure(argv);
  result = chemin_direct(player = pos_depart(tab, player), pos_arrive(tab));
  if (result > -1 && result <= player.point)
    my_putstr("OK\n");
  else if (go_bonus(tab, player))
    my_putstr("OK\n");
  else
    my_putstr("KO\n");
}

void start(int argc, char **argv)
{
  char *ret;
  
  if (argc == 4 && digit(argv[1]) && digit(argv[2]))
    {
      ret = open_map(argv[3]);
      if (my_strcmp(ret, "0") != 0)
	{
	  algo(argv, ret);
	}
      else
	{
	  my_putstr("Veuillez entrer des arguments valides : [nombre de vies]");
	  my_putstr("[valeur des resources][fichier map]\n");
	}
    }
  else
    {
      my_putstr("Veuillez entrer des arguments valides : [nombre de vies]");
      my_putstr("[valeur des resources][fichier map]\n");
    }
}
