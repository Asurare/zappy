/*
** determoine_action.c for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  May Jun 23 13:45:25 2016 Jonathan BITEAU
** Last update Jan Jun 26 08:18:51 2016 Jonathan BITEAU
*/

# include "determine_action.h"

static void nothing_seen(t_client *cl, int *loop, e_state ori)
{
  static int  r_loop;

  if (r_loop == 0)
  {
    *loop += 1;
    r_loop = *loop + cl->lvl - 1;
  }
  if (r_loop != 0)
  {
    cb_write(cl->buff, (cl->st == AHEAD ? "avance\n" :
                          (ori == RIGHT ? "droite\n" : "gauche\n")));
    r_loop -= 1;
    cl->st = (r_loop == 0 ? ori : AHEAD);
  }
}

static int take_if_food_or_other(t_client *cl)
{
  char  **tab;
  int   ct;

  ct = -1;
  if (cl->seeing == NULL)
    return (0);
  tab = str_to_wordtab(cl->seeing[0], ' ');
  cb_reset(cl->buff);
  if (count_players(tab) > 1)
    return (0);
  while (tab[++ct] && ct < 5)
  {
    if (strcmp(tab[ct], "joueur") != 0)
    {
      cb_write(cl->buff, "prend ");
      cb_write(cl->buff, tab[ct]);
      cb_write(cl->buff, "\n");
    }
  }
  free_tab(tab);
  return (0);
}

int    (*action[2])(t_client *) =
{
  &lin,
  &der,
  NULL
};

void determine_action(t_client *cl, __attribute__((unused))char **tab)
{
  static int      loop;
  static e_state  ori;

  if (take_if_food_or_other(cl) == 1)
    loop = 0;
  if (ori == AHEAD)
    ori = RIGHT;
  nothing_seen(cl, &loop, ori);
  if (loop >= (cl->map[0] < cl->map[1] ?
                            cl->map[0] : cl->map[1]))
  {
    loop = 0;
    ori = (ori == RIGHT ? LEFT : RIGHT);
    cl->st = AHEAD;
  }
}
