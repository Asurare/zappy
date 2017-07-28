/*
** determoine_action.c for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  May Jun 23 13:45:25 2016 Jonathan BITEAU
** Last update Sun Jun 26 22:37:09 2016 Florian Videau
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

int    (*action[3])(t_client *) =
{
  &lin,
  &der,
  NULL
};

static int get_brdcs(char **tab, t_client *cl, int ct)
{
  char  *tmp;

  if (cl->lvl <= 2 && (action[cl->lvl - 1])(cl) == 0)
  {
    while (tab[++ct])
      if ((tmp = strstr(tab[ct], "message")) != NULL)
      {
        cl->mode = VOIR;
        return (1);
      }
    cb_write(cl->buff, see_or_broadcast(cl));
    cl->mode = BROADCAST;
  }
  else
    cl->mode = VOIR;
  return (0);
}

static int          elv(t_client *cl, char **tab, int *same)
{
  int ct;
  int cmp;

  ct = -1;
  cmp = 0;
  while (tab[++ct])
  {
    if (strncmp(tab[ct], "niveau actuel", strlen("niveau actuel")) == 0)
    {
      cl->lvl = get_level(tab[ct]);
      *same = 0;
    }
    if (strncmp(tab[ct], "elevation en cours",
        strlen("elevation en cours")) == 0)
      cmp += 1;
  }
  if (*same == 1)
    return (0);
  ct = -1;
  if (cmp != 0 && cl->mode == BROADCAST)
    return (0);
  get_brdcs(tab, cl, ct);
  return (-1);
}

static int infinite_loop(t_client *cl, int *same, int *tmp, int *loop)
{
  if (*tmp == 2)
    *same = 1;
  if (*same == 1)
    return (1);
  if (*same == 0 && cl->br_mess == NULL)
    if (take_if_food_or_other(cl) == 1)
      *loop = 0;
  return (0);
}

void determine_action(t_client *cl, char **tab)
{
  static int      loop;
  static e_state  ori;
  static int      same;
  int             tmp;

  cl->br_mess = NULL;
  if ((tmp = get_br_mess(cl, tab)) == 1)
  {
    cl->mode = VOIR;
    return;
  }
  if (infinite_loop(cl, &same, &tmp, &loop) == 1)
    return;
  if ((elv(cl, tab, &same) == 0 && cl->mode == VOIR) || cl->mode == BROADCAST)
    return;
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
