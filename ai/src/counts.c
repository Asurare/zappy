/*
** counts.c for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  Jan Jun 26 21:42:47 2016 Jonathan BITEAU
** Last update Jan Jun 26 21:43:56 2016 Jonathan BITEAU
*/

# include "counts.h"

int  count_players(char **tab)
{
  int ct;
  int nbr;

  ct = -1;
  nbr = 0;
  while (tab[++ct])
    if (strcmp(tab[ct], "joueur") == 0)
      nbr += 1;
  return (nbr);
}

int  count_ress(char **tab, char *ress)
{
  int ct;
  int nbr;

  ct = -1;
  nbr = 0;
  while (tab[++ct])
  {
    if (strcmp(tab[ct], ress) == 0)
      nbr += 1;
  }
  free(tab);
  return (nbr);
}
