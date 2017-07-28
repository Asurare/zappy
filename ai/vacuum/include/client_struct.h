/*
** client_struct.h for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/include
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  May Jun 23 13:32:26 2016 Jonathan BITEAU
** Last update Jan Jun 26 02:08:25 2016 Jonathan BITEAU
*/

#ifndef CLIENT_STRUCT_H_
# define CLIENT_STRUCT_H_

# include <stdbool.h>

# include "circ_buffer.h"

typedef struct  s_inv
{
  char  name[20];
  int   nbr;
  struct s_inv *next;
}               t_inv;

typedef enum  s_state
{
  AHEAD,
  LEFT,
  RIGHT
}             e_state;

typedef enum  s_mode
{
  VOIR,
  BROADCAST
}             e_mode;

typedef struct	s_client
{
  char		*ip;
  int		port;
  int		fd;
  t_circ_buff *buff;
  t_circ_buff *recv;
  char    *team_name;
  int     id;
  int     pos[2];
  int     map[2];
  int     lvl;
  e_mode  mode;
  t_inv   *inv;
  e_state st;
  char    **seeing;
  int     max;
  int     ori;
  int     search;
  char    *br_mess;
  int     size_seen;
  bool		run;
  bool		read;
  bool		connected;
}		t_client;

#endif /* CLIENT_STRUCT_H_ */
