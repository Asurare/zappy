/*
** actions.c for actions in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by biteau_j
** Login   <biteau_j@epitech.net>
**
** Started on  Tue Jun  7 18:14:45 2016 biteau_j
** Last update Jan Jun 26 02:33:44 2016 Jonathan BITEAU
*/

# include "client.h"

int dell_bracets(char *cmds)
{
  int ct;
  int tmp;

  tmp = -1;
  while (cmds[++tmp] && cmds[tmp] != '{');
  tmp += 1;
  ct = -1;
  while (cmds[++ct])
    cmds[ct] = cmds[ct + tmp];
  cmds[strlen(cmds) - 2] = '\0';
  return (0);
}

int begin(t_client *cl, char *cmds)
{
  is_spaces(cmds) == false ? get_nslots(cmds, cl) :
                            get_size(cl, str_to_wordtab(cmds, ' '));
  if (strlen(cmds) < 5)
    return (0);
  return (0);
}

static int names_if_unsent(t_client *cl)
{
  static bool named;
  if (named == false)
  {
    named = true;
    dprintf(cl->fd, "%s\nvoir\n", cl->team_name);
    return (1);
  }
  return (0);
}

static void do_all_actions(t_client *cl, char *str, int *passed)
{
  if (isdigit(str[0]) != 0 && cl->map[0] == 0 && cl->map[1] == 0)
    begin(cl, str);
  if (strstr(str, "{") != NULL && dell_bracets(str) == 0)
  {
    *passed += 1;
    get_inv_or_see(cl, str);
  }
}

int	do_actions(t_client *cl, char *cmds)
{
  char        *tmp;
  int         passed;
  char        **tab;
  int         ct;

  if (names_if_unsent(cl) == 1)
    return (0);
  tab = str_to_wordtab(cmds, '\n');
  passed = 0;
  ct = -1;
  while (tab[++ct])
    do_all_actions(cl, tab[ct], &passed);
  if (passed == 0)
  {
    free_tab(tab);
    return (0);
  }
  determine_action(cl, tab);
  cb_write(cl->buff, (tmp = see_or_broadcast(cl)));
  free(tmp);
  free_tab(tab);
  return (42);
}
