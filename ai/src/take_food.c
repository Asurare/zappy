/*
** take_food.c for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  Jan Jun 26 21:39:19 2016 Jonathan BITEAU
** Last update Jan Jun 26 21:48:50 2016 Jonathan BITEAU
*/

# include "take_food.h"

int take_if_food_or_other(t_client *cl)
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
