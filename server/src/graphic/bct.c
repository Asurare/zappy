/*
** bct.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src/graphic
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Fri Jun 24 03:33:55 2016 Florian Videau
** Last update Sun Jun 26 07:51:57 2016 Florian Videau
*/

#include <stdlib.h>
#include "cmd_user.h"
#include "graphics.h"
#include "send_msg.h"
#include "server.h"
#include "types/vector.h"

int	my_bct(S_CMD_GRAPH_B_ARGS)
{
  send_msg(client_fd, "bct %ld %ld %d %d %d %d %d %d %d\n", pos->x, pos->y,
	   g_map[pos->y][pos->x].ressources[NOURRITURE],
	   g_map[pos->y][pos->x].ressources[LINEMATE],
	   g_map[pos->y][pos->x].ressources[DERAUMERE],
	   g_map[pos->y][pos->x].ressources[SIBUR],
	   g_map[pos->y][pos->x].ressources[MENDIANE],
	   g_map[pos->y][pos->x].ressources[PHIRAS],
	   g_map[pos->y][pos->x].ressources[THYSTAME]);
  return (0);
}

int	bct(S_CMD_USER_ARGS)
{
  return (my_bct(client_fd, &(t_vect){.x = atol(cmd[1]), .y = atol(cmd[2])}));
}
