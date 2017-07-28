/*
** catch_sigint.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jun 15 20:28:36 2016 Bastien DHIVER
** Last update Sun Jun 26 05:13:49 2016 Bastien DHIVER
*/

#include <stdlib.h>
#include <signal.h>
#include "server.h"
#include "zappy_time.h"
#include "types/box.h"
#include "send_msg.h"
#include "graphics.h"

void	catch_sigint(int signum)
{
  (void)signum;
  free(g_args.team_names);
  free_time_list();
  flush_msgs_struct_to_send();
  flush_graph_client_list();
  free_map();
  exit(0);
}
