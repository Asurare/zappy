/*
** cmd_voir_action_utils.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sun Jun 19 15:12:38 2016 Florian Videau
** Last update Mon Jun 20 14:54:41 2016 Florian Videau
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	calc_nb_box(int level)
{
  int	nb_box;
  int	line_len;
  int	i;

  i = -1;
  line_len = 1;
  nb_box = line_len;
  while (++i < level)
    {
      line_len += 2;
      nb_box += line_len;
    }
  return (nb_box);
}

static int	calc_response_len(char **tab, int tablen)
{
  int		i;
  int		resp_len;

  resp_len = 3 + tablen;
  i = -1;
  while (++i < tablen)
    resp_len += strlen(tab[i]);
  return (resp_len);
}

char	*assemble_response(char **tab, int tablen)
{
  char	*response;
  int	resp_len;
  int	i;

  resp_len = calc_response_len(tab, tablen);
  if (!(response = calloc(resp_len, sizeof(char))))
    return (NULL);
  response[0] = '{';
  i = -1;
  while (++i < tablen)
    {
      strcat(response, !i ? tab[i] + 1 : tab[i]);
      response[strlen(response)] = ',';
      free(tab[i]);
    }
  response[strlen(response) - 1] = '}';
  response[strlen(response)] = '\n';
  return (response);
}
