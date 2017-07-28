/*
** client.h for client in /home/biteau_j/rendu/tek2/PSU/PSU_2015_myirc/src/client
**
** Made by biteau_j
** Login   <biteau_j@epitech.net>
**
** Started on  Sat Jun  4 18:06:56 2016 biteau_j
** Last update Sun Jun 26 22:41:34 2016 Florian Videau
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# define _GNU_SOURCE

# include <sys/wait.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/select.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# define BOLD "\033[1m"
# define RED "\033[31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"

# include "finders.h"
# include "str_to_wordtab.h"
# include "inv_and_see.h"
# include "determine_action.h"
# include "broadcast.h"
# include "take_food.h"
# include "lin.h"
# include "der.h"

/*
**	read_write.c
*/
void	write_srv(t_client *);
void	read_srv(t_client *);
void	read_cmd(t_client *);

/*
**	actions.c
*/
int	do_actions(t_client *, char *);

/*
**	server.c
*/
int	server_connect(t_client *, char **);

/*
**	loop.c
*/
void	free_clt();
int	loop(t_client *, int);

/*
**	init.c
*/
void	init(t_client **);

/*
**	set_fds.c
*/
void	set_fds(fd_set *, fd_set *, t_client *);

#endif /* CLIENT_H_ */
