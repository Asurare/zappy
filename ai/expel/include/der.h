/*
** der.h for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/include
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  Jan Jun 26 03:39:13 2016 Jonathan BITEAU
** Last update Jan Jun 26 07:43:30 2016 Jonathan BITEAU
*/

#ifndef DER_H_
# define DER_H_

# include <string.h>
# include <ctype.h>

# include "client_struct.h"
# include "str_to_wordtab.h"

int der(t_client *);
int  count_players(char **);
int  get_level(char *);

#endif /* DER_H_ */
