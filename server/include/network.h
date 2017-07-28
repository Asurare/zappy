/*
** network.h for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/include
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jun 15 15:31:35 2016 Bastien DHIVER
** Last update Fri Jun 24 02:17:35 2016 Bastien DHIVER
*/

#ifndef NETWORK_H_
# define NETWORK_H_

# include <sys/types.h>
# include <sys/socket.h>

# define MAX_STR_PORT_LEN	(6)
# define SELECT_WAIT_USEC	(1000)

typedef struct			s_servInfo
{
  int				listener;
  fd_set			master;
  fd_set			read_fds;
  fd_set			write_fds;
  int				fd_max;
}				t_servInfo;

int				run_server(void);
void				*get_in_addr(struct sockaddr *);
int				handle_new_connections(void);
int				handle_client_data(int);
int				how_many_data_in_fd(int);
int				client_leaving(int);
int				receive_user_cmd(int);
int				execute_client_cmds(int, char *);
void				init_select_use(void);

#endif /* NETWORK_H_ */
