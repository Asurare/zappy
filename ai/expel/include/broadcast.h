/*
** broadcast.h for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/include
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  Jul Jun 25 21:55:58 2016 Jonathan BITEAU
** Last update Jan Jun 26 02:25:42 2016 Jonathan BITEAU
*/

#ifndef BROADCAST_H_
# define BROADCAST_H_

#define _GNU_SOURCE

# include <stdio.h>
# include <string.h>

# include "client_struct.h"
# include "client.h"
# include "str_to_wordtab.h"

char *see_or_broadcast(t_client *);
int get_br_mess(t_client *cl, char **tab);

#endif /* BROADCAST_H_ */
