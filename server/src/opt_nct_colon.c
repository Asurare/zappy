/*
** opt_nct_colon.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Jun 14 17:59:24 2016 Bastien DHIVER
** Last update Sun Jun 26 15:05:30 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include "server.h"
#include "msg.h"

char	opt_n(S_OPTS_ARGV)
{
  int	i;
  int	tmp;

  i = parse->optind - 2;
  tmp = 0;
  while (parse->av[++i] && parse->av[i][0] != '-')
    tmp++;
  if (!(g_args.team_names = calloc(tmp + 1, sizeof(*g_args.team_names))))
    {
      print_err(ERR_MALLOC);
      exit(1);
    }
  i = parse->optind - 2;
  tmp = -1;
  while (parse->av[++i] && parse->av[i][0] != '-')
    {
      g_args.team_names[++tmp] = parse->av[i];
      g_args.nb_teams++;
    }
  parse->check[OPT_N] = 1;
  return (OPT_N);
}

char	opt_c(S_OPTS_ARGV)
{
  if (str_to_long(parse->val, &g_args.allowed_users))
    return (print_err(ERR_ALLOWED_USERS_LONG), -1);
  if (g_args.allowed_users < 0)
    return (print_err(ERR_ALLOWED_USERS_ZERO), -1);
  parse->check[OPT_C] = 1;
  return (OPT_C);
}

char	opt_t(S_OPTS_ARGV)
{
  if (str_to_long(parse->val, &g_args.delay))
    return (print_err(ERR_DELAY_LONG), -1);
  if (g_args.delay < 0)
    return (print_err(ERR_DELAY_ZERO), -1);
  parse->check[OPT_T] = 1;
  return (OPT_T);
}

char	opt_colon(S_OPTS_ARGV)
{
  parse->check[OPT_COLON] = 1;
  return (-1);
}
