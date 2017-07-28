/*
** opt_pxyh_ask.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Jun 14 19:30:25 2016 Bastien DHIVER
** Last update Thu Jun 23 21:19:46 2016 Bastien DHIVER
*/

#include "server.h"
#include "msg.h"

char	opt_p(S_OPTS_ARGV)
{
  if (str_to_int(parse->val, &g_args.port))
    return (print_err(ERR_PORT_NOT_INT), -1);
  if (!port_in_range(g_args.port))
    return (print_err(ERR_PORT_NOT_IN_RANGE), -1);
  parse->check[OPT_P] = 1;
  return (OPT_P);
}

char	opt_x(S_OPTS_ARGV)
{
  if (str_to_long(parse->val, &g_args.x))
    return (print_err(ERR_WIDTH_NOT_LONG), -1);
  if (g_args.x < 0)
    return (print_err(ERR_WIDTH_LOWER_ZERO), -1);
  parse->check[OPT_X] = 1;
  return (OPT_X);
}

char	opt_y(S_OPTS_ARGV)
{
  if (str_to_long(parse->val, &g_args.y))
    return (print_err(ERR_HEIGHT_NOT_LONG), -1);
  if (g_args.y < 0)
    return (print_err(ERR_HEIGHT_LOWER_ZERO), -1);
  parse->check[OPT_Y] = 1;
  return (OPT_Y);
}

char	opt_h(S_OPTS_ARGV)
{
  display_usage();
  parse->check[OPT_H] = 1;
  return (0);
}

char	opt_ask(S_OPTS_ARGV)
{
  parse->check[OPT_ASK] = 1;
  return (-1);
}
