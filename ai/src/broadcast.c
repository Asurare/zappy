/*
** broadcast.c for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  Jul Jun 25 21:53:23 2016 Jonathan BITEAU
** Last update Sun Jun 26 22:28:01 2016 Bastien DHIVER
*/

# include "broadcast.h"

static int lvl_players_needed(t_client *cl)
{
  int   ct;
  char  **tab;
  int   p_nbr;

  p_nbr = (cl->lvl == 1 ? 1 :
    ((cl->lvl == 2 || cl->lvl == 3) ? 2 :
    ((cl->lvl == 4 || cl->lvl == 5) ? 4 : 6)));
  if (cl->seeing == NULL)
    return (0);
  tab = str_to_wordtab(cl->seeing[0], ' ');
  ct = -1;
  while (tab[++ct])
    p_nbr -= (strcmp(tab[ct], "joueur") == 0 ? 1 : 0);
  free_tab(tab);
  return (p_nbr < 0 ? 0 : p_nbr);
}

char *see_or_broadcast(t_client *cl)
{
  char  *tmp;
  char  *to_send;

  asprintf(&tmp, "%d:%d", lvl_players_needed(cl), cl->lvl);
  if (cl->mode != VOIR)
    asprintf(&to_send, "broadcast %s\nvoir\ninventaire\n", tmp);
  free(tmp);
  return ((cl->mode == VOIR ? strdup("voir\ninventaire\n") : to_send));
}

static int calc_pos_to_go(t_client *cl, int ori, int r_lvl)
{
  if (r_lvl != cl->lvl)
    return (0);
  cb_write(cl->buff,
	   (ori == 1 ? "avance\n" :
	    (ori == 2 ? "avance\ngauche\navance\n" :
	     (ori == 3 ? "gauche\navance\n" :
	      (ori == 4 ? "gauche\navance\ngauche\navance\n" :
	       (ori == 5 ? "gauche\ngauche\navance\n" :
		(ori == 6 ? "droite\navance\ndroite\navance\n" :
		 (ori == 7 ? "droite\nvance\n" :
		  (ori == 8 ? "avance\ndroite\navance\n" : "")))))))));
  return (1);
}

static int ret_value(t_client *cl, int *ct, int *ori, int *r_lvl)
{
  while (cl->br_mess[++(*ct)])
    if (isdigit(cl->br_mess[*ct]) != 0)
    {
      if (*ori < 0)
      {
        *ori = cl->br_mess[*ct] - 48;
        if (count_ress(str_to_wordtab(cl->seeing[0], ' '), "joueur") >= 2)
          return (2);
      }
      else
        *r_lvl = cl->br_mess[*ct] - 48;
    }
  return (0);
}

int get_br_mess(t_client *cl, char **tab)
{
  char  *tmp;
  int   ct;
  int   ori;
  int   r_lvl;

  ct = -1;
  tmp = NULL;
  while (tab[++ct])
    if (strstr(tab[ct], "message") != NULL)
      tmp = strstr(tab[ct], "message");
  if (tab[ct] == NULL && tmp == NULL)
    return (0);
  tmp += 8;
  ct = -1;
  ori = -1;
  r_lvl = 0;
  cl->br_mess = strdup(tmp);
  if (ret_value(cl, &ct, &ori, &r_lvl) == 2)
    return (2);
  return (calc_pos_to_go(cl, ori, r_lvl));
}
