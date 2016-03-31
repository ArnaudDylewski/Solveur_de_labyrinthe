#include "prototype.h"

char *open_map(char *map)
{
  int file;
  char *ret;
  
  ret = malloc(sizeof(char) * 1024);
  file = open(map, O_RDONLY);
  if (file != -1)
    {
      read(file, (char *)ret, 1024);
      close(file);
      return (ret);
    }
  else
    return ("0");
}

char **alloc_tab(char **tab, char *ret, int i)
{
  int size;
  int j;

  
  size = my_strlen(ret)/i;
  for(j=0;j<(i-1);j++)
    {
      tab[j]= malloc(sizeof(char *) * size);
    }
  return(tab);
}

char **tab_map(char *ret)
{	
  int i;
  int j;
  int k;
  char **tab;
  
  i = 0;
  j = 0;
  k = 0;
  while (ret[i] != '\n')
    i++;
  tab = malloc(sizeof(char *) * i);
  tab = alloc_tab(tab, ret, i);
  i = 0;
  while (ret[i] != '\0')
    {
      if (ret[i] != '\n')
	{
	  tab[j][k] = ret[i];
	  k++;
	}
      else
	{
	  k = 0;
	  j++;
	}
      i++;
    }
  free(ret);
  return(tab);
}

void aff_map(char** tab)
{
  int i;
  int j;
  
  i = 0;
  while(tab[i] != '\0')
    {
      j = 0;
      while(tab[i][j] != '\0')
	{
	  my_putchar(tab[i][j]);
	  j++;
	}
      i++;
      my_putchar('\n');
    }
}
