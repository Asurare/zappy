/*
** str_to_wordtab.h for str_to_wordtab in /home/biteau_j/rendu/tek2/PSU/PSU_2015_myirc/include
**
** Made by biteau_j
** Login   <biteau_j@epitech.net>
**
** Started on  Thu May 26 09:43:38 2016 biteau_j
** Last update May Jun 23 14:32:18 2016 Jonathan BITEAU
*/

#ifndef STR_TO_WORDTAB_H_
# define STR_TO_WORDTAB_H_

# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

char	**str_to_wordtab(char *, char c);
int	tab_size(char **);
void	free_tab(char **);
char	**get_params(char *);

# endif /* STR_TO_WORDTAB_H_ */
