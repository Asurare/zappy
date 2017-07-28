/*
** finders.c for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  May Jun 23 13:23:02 2016 Jonathan BITEAU
** Last update Jul Jun 25 22:07:05 2016 Jonathan BITEAU
*/

# include "finders.h"

void get_size(t_client *cl, char **tab)
{
  cl->map[0] = atoi(tab[0]);
  cl->map[1] = atoi(tab[1]);
  free_tab(tab);
}

void get_nslots(char *buff, t_client *cl)
{
  cl->max = atoi(buff);
}

bool is_spaces(char *cmds)
{
  int ct;

  ct = -1;
  while (cmds[++ct])
    if (cmds[ct] == ' ')
      return (true);
  return (false);
}

int count_lines(char *str)
{
  int ct;
  int nbr;
  char **tab;

  ct = -1;
  nbr = 0;
  tab = str_to_wordtab(str, '\n');
  while (tab[++ct])
    nbr += (strncmp(tab[ct], "message", strlen("message")) != 0 ? 1 : 0);
  free_tab(tab);
  return (nbr - 1);
}

int find_nbr(char *cmds)
{
  int   ct;

  ct = 0;
  while (cmds[ct])
    if (isdigit(cmds[ct++]) != 0)
      return (1);
  return (0);
}
