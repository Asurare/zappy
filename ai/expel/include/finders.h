/*
** finders.h for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/include
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  May Jun 23 13:24:15 2016 Jonathan BITEAU
** Last update Jul Jun 25 18:14:53 2016 Jonathan BITEAU
*/

#ifndef FINDERS_H_
# define FINDERS_H_

# include <ctype.h>

# include "str_to_wordtab.h"
# include "client_struct.h"

void get_size(t_client *, char **);
void get_nslots(char *, t_client *);
bool is_spaces(char *);
int find_nbr(char *);
int count_lines(char *);

#endif /* FINDERS_H_ */
