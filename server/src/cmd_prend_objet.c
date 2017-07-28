/*
** cmd_prend_objet.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Jun 16 15:48:12 2016 Bastien DHIVER
** Last update Fri Jun 24 15:52:18 2016 Bastien DHIVER
*/

#include "cmd_user.h"
#include "cmd_user_actions.h"
#include "zappy_time.h"

int	cmd_prend_objet(_S_CMD_USER_ARGS)
{
  args->ft_p = cmd_prend_objet_action;
  insert_in_time(7, args);
  return (0);
}
