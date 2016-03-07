/*
** main.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware/src
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:26:06 2016 Eric DESCHODT
<<<<<<< HEAD
<<<<<<< HEAD
** Last update Mon Mar  7 15:31:24 2016 Eric DESCHODT
=======
** Last update Mon Mar  7 15:24:57 2016 Antoine Roig
>>>>>>> 1623b309beae51b93573b7af61439be17cebeeec
=======
** Last update Mon Mar  7 15:31:30 2016 Antoine Roig
>>>>>>> f07e997e4f6be9845dfe648bcab1293b8a7fdd15
*/

#include "corewar.h"

void    *xmalloc(int size)
{
  void  *element;

  element = malloc(size);
  if (!element)
    exit(EXIT_FAILURE);
  return (element);
}

t_vm	*new_vm(t_vm *vm)
{
  vm = xmalloc(sizeof(*vm));
  vm->begin = NULL;
  vm->end = vm->begin;
  vm->nb = 0;
  return (vm);
}

t_champlist	*new_champ(t_champlist *champ, int id, int cycle)
{
  champ = xmalloc(sizeof(*champ));
  champ->begin = NULL;
  champ->end = champ->begin;
  champ->id = id;
  champ->next = NULL;
  champ->begin = malloc(sizeof(t_instru));
  champ->current = champ->begin;
  champ->begin->ope.comment = "yo";
  champ->begin->ope.nbr_cycles = cycle;
  champ->begin->current_cycle = 0;
  champ->begin->next = champ->begin;
  return (champ);
}

void	add_champ_vm(t_vm *vm, t_champlist *champ, int nb_champ, int cycle)
{
  champ = new_champ(champ, nb_champ, cycle);
  if (vm->begin == NULL)
    {
      vm->begin = champ;
      vm->end = champ;
      vm->nb = 1;
    }
  else
    {
      champ->next = vm->begin;
      vm->begin->prev = champ;
      vm->begin = champ;
      vm->nb = vm->nb + 1;
    }
}

void	launch_vm(t_vm *vm, int nb_champ)
{
  int		i;
  t_champlist	*champ;
  int		cycle;

  cycle = 2;
  i = 0;
  while (i < nb_champ)
    {
      champ = NULL;
      add_champ_vm(vm, champ, i, cycle);
      cycle *= 2;
      vm->nb++;
      i++;
    }
}

void    show_list(t_vm *vm)
{
  t_champlist        *tmp;

  tmp = vm->begin;
  while (tmp != NULL)
    {
      my_printf("id = %d\ncomment = %s\nnb cycle = %d\n",
		(tmp->id), tmp->begin->ope.comment, tmp->begin->ope.nbr_cycles);
      tmp = tmp->next;
    }

}

int	main(int ac, char **av)
{
  int	nb_champ;
  t_vm	*vm;

  ac = ac;
  vm = NULL;
  nb_champ = atoi(av[1]);
  vm = new_vm(vm);
  launch_vm(vm, nb_champ);
  show_list(vm);
  start_vm(vm);
  return (0);
}
