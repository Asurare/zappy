/*
** server.h for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/include
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Tue Jun 14 12:37:59 2016 Florian Videau
** Last update Sun Jun 26 21:00:11 2016 Bastien DHIVER
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <stddef.h>
# include <stdio.h>
# include "cmd_user.h"
# include "zappy_time.h"
# include "types/box.h"
# include "network.h"

# define DEFAULT_DELAY		(100)

# define print_err(...)		fprintf(stderr, __VA_ARGS__)

# define OPTSTRING		"p:x:y:n:c:t:h"

# define MAX_LEVEL		(8)

enum				e_opt
{
  OPT_P = 1,
  OPT_X,
  OPT_Y,
  OPT_N,
  OPT_C,
  OPT_T,
  OPT_H,
  OPT_ASK,
  OPT_COLON,
  MAX_OPT
};

typedef	struct			s_args
{
  char				*prg_name;
  int				port;
  long				x;
  long				y;
  char				**team_names;
  size_t			nb_teams;
  long				allowed_users;
  long				delay;
}				t_args;

extern t_args			g_args;
extern struct time_listq	g_time_listq;
extern struct s_box		**g_map;
extern struct msg_listq		g_msg_listq;
extern t_servInfo		*g_servInfo;
extern int			*g_avail_team_slot;
extern struct graph_listq	g_graph_listq;

typedef struct			s_arg_parse
{
  int				ac;
  char				**av;
  int				optind;
  char				*val;
  int				*check;
}				t_arg_parse;

# define S_OPTS_ARGV		t_arg_parse *parse

typedef	struct			s_opts
{
  char				name;
  char				(*ft_p)(S_OPTS_ARGV);
}				t_opts;

# define FOOD_UNIT_VALUE	(126)

void				catch_sigint(int);
void				display_usage(void);

int				str_to_int(char *, int *);
int				str_to_long(char *, long int *);

int				port_in_range(int);

char				opt_p(S_OPTS_ARGV);
char				opt_x(S_OPTS_ARGV);
char				opt_y(S_OPTS_ARGV);
char				opt_h(S_OPTS_ARGV);
char				opt_ask(S_OPTS_ARGV);

char				opt_n(S_OPTS_ARGV);
char				opt_c(S_OPTS_ARGV);
char				opt_t(S_OPTS_ARGV);
char				opt_colon(S_OPTS_ARGV);

void				*xmalloc(size_t);

size_t				how_many_in(char, char *);
size_t				how_many_str_in(char *, char *);

char				**str_split(char *, char *);
char				**str_split_str(char *, char *);
void				str_join(char **, char *, char *);

char				*epur_str(char *);

#endif /* SERVER_H_ */
