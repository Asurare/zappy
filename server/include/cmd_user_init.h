/*
** cmd_user_init.h for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/include
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jun 22 14:31:48 2016 Bastien DHIVER
** Last update Fri Jun 24 15:57:49 2016 Bastien DHIVER
*/

#ifndef CMD_USER_INIT_H_
# define CMD_USER_INIT_H_

# include "cmd_user.h"

static const t_cmd_user	g_cmd_user_tab[] =
	{{"avance", cmd_avance},
	{"droite", cmd_droite},
	{"gauche", cmd_gauche},
	{"voir", cmd_voir},
	{"inventaire", cmd_inventaire},
	{"prend", cmd_prend_objet},
	{"pose", cmd_pose_objet},
	{"expulse", cmd_expulse},
	{"broadcast", cmd_broadcast},
	{"incantation", cmd_incantation},
	{"fork", cmd_fork},
	{"connect_nbr", cmd_connect_nbr}
};

#endif /* !CMD_USER_INIT_H_ */
