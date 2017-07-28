/*
** graphics.h for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/include
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 03:11:53 2016 Florian Videau
** Last update Sun Jun 26 17:07:25 2016 Florian Videau
*/

#ifndef GRAPHICS_H_
# define GRAPHICS_H_

# include <sys/queue.h>
# include "cmd_user.h"
# include "types/egg.h"
# include "types/vector.h"
# include "types/user.h"
# include "types/userList.h"

TAILQ_HEAD(graph_listq, s_graph_listq);

struct				s_graph_listq
{
  int				client_fd;
  TAILQ_ENTRY(s_graph_listq)	tailq;
};

# define S_CMD_GRAPH_B_ARGS	int client_fd, t_vect *pos
# define S_CMD_GRAPH_P_ARGS	int client_fd, t_user *player, void *more
# define S_CMD_GRAPH_E_ARGS	int client_fd, t_egg *egg
# define S_CMD_GRAPH_MST_ARGS	int client_fd

t_userList			*find_user_from_id(int);

int				my_msz(S_CMD_GRAPH_MST_ARGS);
int				msz(S_CMD_USER_ARGS);
int				my_bct(S_CMD_GRAPH_B_ARGS);
int				bct(S_CMD_USER_ARGS);
int				my_mct(S_CMD_GRAPH_MST_ARGS);
int				mct(S_CMD_USER_ARGS);
int				my_tna(S_CMD_GRAPH_MST_ARGS);
int				tna(S_CMD_USER_ARGS);
int				my_pnw(S_CMD_GRAPH_P_ARGS);
int				my_ppo(S_CMD_GRAPH_P_ARGS);
int				ppo(S_CMD_USER_ARGS);
int				my_plv(S_CMD_GRAPH_P_ARGS);
int				plv(S_CMD_USER_ARGS);
int				my_pin(S_CMD_GRAPH_P_ARGS);
int				pin(S_CMD_USER_ARGS);
int				my_pex(S_CMD_GRAPH_P_ARGS);
int				my_pbc(S_CMD_GRAPH_P_ARGS);
int				my_pic(S_CMD_GRAPH_P_ARGS);
int				my_pie(S_CMD_GRAPH_P_ARGS);
int				my_pfk(S_CMD_GRAPH_P_ARGS);
int				my_pdr(S_CMD_GRAPH_P_ARGS);
int				my_pgt(S_CMD_GRAPH_P_ARGS);
int				my_pdi(S_CMD_GRAPH_P_ARGS);
int				my_enw(S_CMD_GRAPH_E_ARGS);
int				my_eht(S_CMD_GRAPH_E_ARGS);
int				my_ebo(S_CMD_GRAPH_E_ARGS);
int				my_edi(S_CMD_GRAPH_E_ARGS);
int				my_sgt(S_CMD_GRAPH_MST_ARGS);
int				sst(S_CMD_GRAPH_MST_ARGS);
int				my_seg(S_CMD_GRAPH_P_ARGS);
int				my_smg(char *);
int				my_suc(S_CMD_GRAPH_MST_ARGS);
int				my_sbp(S_CMD_GRAPH_MST_ARGS);

void				send_all_graph_b(t_vect *pos,
						 int (*fct)
						 (S_CMD_GRAPH_B_ARGS));
void				send_all_graph_p(t_user *, void *, int (*fct)
						 (S_CMD_GRAPH_P_ARGS));
void				send_all_graph_e(t_egg *, int (*fct)
						 (S_CMD_GRAPH_E_ARGS));
void				send_all_graph_mst(int (*fct)
						   (S_CMD_GRAPH_MST_ARGS));
int				is_graph_client(int fd);

void				say_hi_to_graph_client(int);

void				remove_graph_client_from_fd(int);
void				flush_graph_client_list(void);

#endif /*!GRAPHICS_H_*/
