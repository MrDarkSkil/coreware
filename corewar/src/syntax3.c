/*
** syntax3.c for syntax3.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Thu Mar 24 00:23:38 2016 Antoine Roig
** Last update Thu Mar 24 02:06:46 2016 Juliani Renaud
*/

#include "corewar.h"

int		is_alpha(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
	  && (my_strcmp(is_cor(str), ".cor") != 0))
	return (0);
      i++;
    }
  return (1);
}

int	check_para(t_dlist *list)
{
  t_list	*tmp;

  tmp = list->begin;
  while (tmp)
    {
      if (is_nbr(tmp->arg) == 0 || is_alpha(tmp->arg) == 0)
	if (tmp == list->begin || (my_strcmp(tmp->prev->arg, "-dump") != 0 &&
				   my_strcmp(tmp->prev->arg, "-a") != 0 &&
				   my_strcmp(tmp->prev->arg, "-n") != 0))
	  {
	    printf("salope\n");
	    exit(0);
	  }
      tmp = tmp->next;
    }
  return (0);
}
