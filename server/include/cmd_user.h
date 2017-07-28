/*
** cmd_user.h for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/include
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Jun 16 13:17:45 2016 Bastien DHIVER
** Last update Sun Jun 26 03:26:46 2016 Bastien DHIVER
*/

#ifndef CMD_USER_H_
# define CMD_USER_H_

# include <unistd.h>
# include "types/box.h"

enum				e_cmds
{
  AVANCE,
  DROITE,
  GAUCHE,
  VOIR,
  INVENTAIRE,
  PREND_OBJET,
  POSE_OBJET,
  EXPULSE,
  BROADCAST,
  INCANTATION,
  FORK,
  CONNECT_NBR,
  MAX_USER_CMD
};

# define S_CMD_USER_ARGS	int client_fd, char **cmd

typedef struct			s_user_args
{
  int				client_fd;
  char				**cmd;
  int				(*ft_p)(S_CMD_USER_ARGS);
}				t_user_args;

# define MAX_LEN_CMD_USER	(11)
# define _S_CMD_USER_ARGS	t_user_args *args

typedef struct			s_cmd_user
{
  char				name[MAX_LEN_CMD_USER];
  int				(*ft_p)(_S_CMD_USER_ARGS);
}				t_cmd_user;

void				init_user_cmd_tab(void);

int				cmd_avance(_S_CMD_USER_ARGS);
int				cmd_droite(_S_CMD_USER_ARGS);
int				cmd_gauche(_S_CMD_USER_ARGS);
int				cmd_voir(_S_CMD_USER_ARGS);
int				cmd_inventaire(_S_CMD_USER_ARGS);
int				cmd_prend_objet(_S_CMD_USER_ARGS);
int				cmd_pose_objet(_S_CMD_USER_ARGS);
int				cmd_expulse(_S_CMD_USER_ARGS);
int				cmd_broadcast(_S_CMD_USER_ARGS);
int				cmd_incantation(_S_CMD_USER_ARGS);
int				cmd_fork(_S_CMD_USER_ARGS);
int				cmd_connect_nbr(_S_CMD_USER_ARGS);

ssize_t				get_team_idx_from_fd(int);
char				*get_team_name_glob_ptr(char *);

int				clients_will_eat(S_CMD_USER_ARGS);
int				hatched_an_egg(S_CMD_USER_ARGS);

void				free_user_split_cmd(char **);
void				__ko_msg(int, char **);
void				__ko_kick_user(int, char **);
void				__reduce_avail_team_slot(int);

void				__say_hi_to_new_client(int, int);
void				__add_new_client(int, char *, int);
void				__say_hi_to_new_graph_client(int);
void				__add_graph_client_in_list(int);
void				add_new_graph_client(int);

int				is_team_name(char *);
int				is_user_on_map(int);
int				__is_a_command(char *);
int				__is_graphic_welcome(char *);
int				__team_slot_available(int);

t_user_args			*generate_t_user_args(int, char **);

#endif /* CMD_USER_H_ */
