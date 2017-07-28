/*
** cmd_user_actions.h for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/include
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sat Jun 18 15:23:06 2016 Bastien DHIVER
** Last update Sun Jun 26 18:02:47 2016 Florian Videau
*/

#ifndef CMD_USER_ACTIONS_H_
# define CMD_USER_ACTIONS_H_

# include "types/box.h"
# include "types/vector.h"

long		get_real_x(long);
long		get_real_y(long);
int		calc_nb_box(int level);
char		*assemble_response(char **tab, int tablen);
t_userList	*find_user(const int);
int		cmd_avance_action(S_CMD_USER_ARGS);
int		cmd_droite_action(S_CMD_USER_ARGS);
int		cmd_gauche_action(S_CMD_USER_ARGS);
int		cmd_voir_action(S_CMD_USER_ARGS);
int		cmd_inventaire_action(S_CMD_USER_ARGS);
int		cmd_prend_objet_action(S_CMD_USER_ARGS);
int		cmd_pose_objet_action(S_CMD_USER_ARGS);
int		cmd_expulse_action(S_CMD_USER_ARGS);
int		cmd_broadcast_action(S_CMD_USER_ARGS);
int		cmd_incantation_action(S_CMD_USER_ARGS);
int		incantation(int);
int		calc_absolute_income(t_user *, t_vect *);
double		find_shortest_dist(double dists[3]);
double		rylttyrxlttx(t_user *, t_vect *);
double		tyltryrxlttx(t_user *, t_vect *);
double		rylttytxltrx(t_user *, t_vect *);
double		tyltrytxltrx(t_user *, t_vect *);
int		get_nb_elem_in_userList(t_userList *);
int		cmd_fork_action(S_CMD_USER_ARGS);
int		check_levels(int level, t_userList *user);

#endif /*!CMD_USER_ACTIONS_H_ */
