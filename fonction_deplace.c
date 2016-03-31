#include "prototype.h"

t_play pos_depart(char** tab, t_play player)
{
  int x;
  int y;
  
  player.x = -1;
  player.y = -1;
  for(x=0;tab[x] != '\0';x++)
    {
      for(y=0;tab[x][y] != '\0';y++)
	{
	  if (tab[x][y] == '@')
	    {
	      player.x = x;
	      player.y = y;
	    }	
	}
    }
  return(player);
}

t_pos pos_arrive(char** tab)
{
  int x;
  int y;
  t_pos arrive;
  
  arrive.x = -1;
  arrive.y = -1;
  for(x=0;tab[x] != '\0';x++)
    {
      for(y=0;tab[x][y] != '\0';y++)
	{
	  if (tab[x][y] == '#')
	    {
	      arrive.x = x;
	      arrive.y = y;
	    }
	}
    }
  return(arrive);
}

int chemin_direct(t_play debut, t_pos arrive)
{
  int x;
  int y;
  int result;

  x = debut.x - arrive.x;
  y = debut.y - arrive.y;
  if (x < 0)
    x=x*-1;
  if (y < 0)
    y=y*-1;
  result=x+y;
  return(result); 
}

int go_bonus(char **tab, t_play player)
{
  int i;
  int j;
  int result;
  t_pos bonus;

  for(i=0;tab[i] != '\0';i++)
    {
      for(j=0;tab[i][j] != '\0';j++)
	{
	  bonus.x = i;
	  bonus.y = j;
	  result = chemin_direct(player, bonus);
	  if(result > -1 && result <= player.point && tab[i][j] == '#')
		return(1);
	  else if(tab[i][j] == '+' && result > -1 && result <= player.point)
	    {
	      player.point = player.point + player.bonus - result;
	      tab[i][j] = ' ';
	      if (go_bonus(tab, player))
		return(1);
	      player.x = i;
	      player.y = j;
	    }
	}
    }
  return(0);
}
