/*
** main.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Jun 14 13:13:27 2016 Bastien DHIVER
** Last update Sat Jun 25 21:05:26 2016 Bastien DHIVER
*/

#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "server.h"
#include "network.h"
#include "msg.h"
#include "cmd_user.h"
#include "send_msg.h"
#include "graphics.h"

t_args			g_args;
struct time_listq	g_time_listq;
struct s_box		**g_map;
struct msg_listq	g_msg_listq;
t_servInfo		*g_servInfo;
int			*g_avail_team_slot;
struct graph_listq	g_graph_listq;

void		display_usage(void)
{
  print_err("USAGE:\n");
  print_err("\t%s -p port -x width -y height -n team_names -c \
client_nbr [-t delay]\n\n", g_args.prg_name);
  print_err("DESCRIPTION:\n");
  print_err("\t-p\tport\n");
  print_err("\t-x\twidth of the world\n");
  print_err("\t-y\theight of the world\n");
  print_err("\t-n\tname_of_team_1 name_of_team2 ...\n");
  print_err("\t-c\tnumber of clients allowed at the game beginning\n");
  print_err("\t-t\ttime delay for executing actions\n");
}

void	init_opts_tab(t_opts *opts)
{
  if ((opts[OPT_P].name = 'p') && (opts[OPT_P].ft_p = opt_p)
      && (opts[OPT_X].name = 'x') && (opts[OPT_X].ft_p = opt_x)
      && (opts[OPT_Y].name = 'y') && (opts[OPT_Y].ft_p = opt_y)
      && (opts[OPT_N].name = 'n') && (opts[OPT_N].ft_p = opt_n)
      && (opts[OPT_C].name = 'c') && (opts[OPT_C].ft_p = opt_c)
      && (opts[OPT_T].name = 't') && (opts[OPT_T].ft_p = opt_t)
      && (opts[OPT_H].name = 'h') && (opts[OPT_H].ft_p = opt_h)
      && (opts[OPT_ASK].name = '?') && (opts[OPT_ASK].ft_p = opt_ask)
      && (opts[OPT_COLON].name = ':') && (opts[OPT_COLON].ft_p = opt_colon))
    return ;
}

int		check_mandatory_args(int *check)
{
  enum e_opt	opt;

  opt = OPT_P;
  while (opt < OPT_T)
    {
      if (!check[opt])
	{
	  print_err("%s: '-%c'\n", ERR_MISS_MANDATORY_OPT,
		    OPTSTRING[opt * 2 - 2]);
	  return (1);
	}
      opt++;
    }
  return (0);
}

int		parse_args(int ac, char **av)
{
  int		opt;
  int		idx;
  t_opts	opts[MAX_OPT];
  char		rv;
  int		check[MAX_OPT];
  t_arg_parse	parse;

  init_opts_tab(opts);
  bzero(&parse, sizeof(parse));
  bzero(check, MAX_OPT * sizeof(*check));
  parse.ac = ac;
  parse.av = av;
  parse.check = check;
  while ((opt = getopt(ac, av, OPTSTRING)) != -1 && !(idx = 0))
    while (++idx < MAX_OPT)
      if (opts[idx].name == opt)
	{
	  parse.optind = optind;
	  parse.val = optarg;
	  if ((rv = opts[idx].ft_p(&parse)) <= 0)
	    return (rv);
	}
  return (check_mandatory_args(check) ? -1 : 1);
}

int			main(int ac, char **av)
{
  int			rv;
  struct sigaction	sa;

  srand(time(NULL));
  bzero(&g_args, sizeof(t_args));
  g_args.prg_name = av[0];
  g_args.delay = DEFAULT_DELAY;
  if (ac == 1)
    return (display_usage(), 1);
  if ((rv = parse_args(ac, av)) != 1)
    return (free(g_args.team_names), (rv == -1) ? 1 : 0);
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  sa.sa_handler = catch_sigint;
  sigaction(SIGINT, &sa, NULL);
  rv = run_server();
  return (free(g_args.team_names), rv);
}
