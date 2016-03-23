/*
** add.c for add.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Sat Mar 19 21:41:30 2016 Antoine Roig
** Last update Wed Mar 23 09:21:02 2016 Eric DESCHODT
*/

#include "corewar.h"

void	swap_carry(t_champ *champ)
{
  if (champ->carry == 1)
    champ->carry = 0;
  else
    champ->carry = 1;
}

int	add(t_args *arg, void *champ, unsigned char *board)
{
  t_byte	nb1;
  t_byte	nb2;
  t_byte        nb3;

  (void)board;
  if (arg[0].type != 1 || arg[1].type != 1 || arg[2].type != 1)
    return (0);
  else
    {
      nb1.byte[0] = ((t_champ *)champ)->reg[arg[0].val - 1][0];
      nb1.byte[1] = ((t_champ *)champ)->reg[arg[0].val - 1][1];
      nb1.byte[2] = ((t_champ *)champ)->reg[arg[0].val - 1][2];
      nb1.byte[3] = ((t_champ *)champ)->reg[arg[0].val - 1][3];
      nb2.byte[0] = ((t_champ *)champ)->reg[arg[1].val - 1][0];
      nb2.byte[1] = ((t_champ *)champ)->reg[arg[1].val - 1][1];
      nb2.byte[2] = ((t_champ *)champ)->reg[arg[1].val - 1][2];
      nb2.byte[3] = ((t_champ *)champ)->reg[arg[1].val - 1][3];
      nb3.full = (nb1.full + nb2.full);
      ((t_champ *)champ)->reg[arg[2].val][0] = nb3.byte[0];
      ((t_champ *)champ)->reg[arg[2].val][1] = nb3.byte[1];
      ((t_champ *)champ)->reg[arg[2].val][2] = nb3.byte[2];
      ((t_champ *)champ)->reg[arg[2].val][3] = nb3.byte[3];
    }
  swap_carry(((t_champ *)champ));
  return (0);
}