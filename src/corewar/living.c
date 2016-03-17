/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Thu Mar 17 16:18:29 2016 Eric DESCHODT
*/

#include "corewar.h"

void		find_living_champion(int result,
				     t_champ *champ)
{
  t_champ	*start;
  t_byte	tmp;
  int		i;

  i = -1;
  while (++i < REG_SIZE)
    tmp.byte[i] = champ->reg[0][i];
  revert_endian(&tmp.full);
  start = champ;
  if (tmp.full == result)
    {
      my_printf("Le champion (%d) est en vie\n", result);
      return;
    }
  start = start->next;
  while (start != champ)
    {
      if (tmp.full == result)
	{
	  my_printf("Le champion (%d) est en vie\n", result);
	  return;
	}
      start = start->next;
    }
  my_printf("Live\n");
}

void		living(t_champ *champ)
{
  int		i;
  int		result;
  t_byte	tmp;

  champ->instru++;
  champ->cursor++;
  i = 0;
  tmp.full = 0;
  result = 0;
  while (i < 4)
    {
      tmp.byte[i] = (*champ->instru);
      champ->instru++;
      champ->cursor++;
      i++;
    }
  revert_endian(&tmp.full);
  result = tmp.full;
  find_living_champion(result, champ);
}