/*
** cmd_user_bye.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Jun 26 02:05:10 2016 Bastien DHIVER
** Last update Sun Jun 26 02:38:03 2016 Bastien DHIVER
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"
#include "cmd_user.h"
#include "msg.h"

void	free_user_split_cmd(char **cmd)
{
  free(*cmd);
  free(cmd);
}

void	__ko_msg(int fd, char **cmd)
{
  send(fd, KO_MSG, strlen(KO_MSG), 0);
  free_user_split_cmd(cmd);
}

void	__ko_kick_user(int fd, char **cmd)
{
  __ko_msg(fd, cmd);
  client_leaving(fd);
}

void	__reduce_avail_team_slot(int team_idx)
{
  g_avail_team_slot[team_idx] -= 1;
}
