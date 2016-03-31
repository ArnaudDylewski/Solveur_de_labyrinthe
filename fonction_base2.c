#include "prototype.h"

int	my_nb_len(int n)
{
  int	nb;
  int	i;
  
  nb = n;
  i = 0;
  while (nb >= 1)
    {
      nb = nb / 10;
      i++;
    }
  return i;
}

void	my_aff_int(int n)
{
  int   d;
  int	s;
  int	a;
  
  d = 1;
  s = my_nb_len(n) - 1;
  while (s > 0)
    {
      d = d * 10;
      s--;
    }
  s = n;
  while (d != 0)
    {
      a = s / d;
      my_putchar(a + 48);
      s = s % d;
      d = d / 10;
    }
}

void	my_put_nbr(int n)
{
  int	s;
  
  s = n;
  if (n == -2147483648)
    {
      my_putstr("-2147483648");
    }
  else if (n < 0)
    {
      my_putchar('-');
      s = s * (-1);
      my_aff_int(s);
    }
  else
    my_aff_int(s);
}
int my_getnbr(char *str)
{
  int i;
  int j;
  int k;
  
  i = 0;
  j = 1;
  k = 0;
  while (((str[i] <= 57) && (str[i] >= 48)) || (str[i] == 43) || (str[i] == 45))
    {
      if (str[i] == '-' && j == -1)
  {
    j *= -1;
    i++;
  }
      else if (str[i] == '-')
  { 
    j *= -1;
    i++;
  }
      else if (str[i] == '+')
  {
    j *= 1;
    i++;
  }
      else
  {
    k = k*10 + str[i] - '0';
    i++;
  }
    }
  k = k * j;
  return (k);
}
