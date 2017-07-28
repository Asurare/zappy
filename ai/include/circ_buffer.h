/*
** circ_buffer.h for circ_buff in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/include
**
** Made by biteau_j
** Login   <biteau_j@epitech.net>
**
** Started on  Mon Jun 13 18:59:29 2016 biteau_j
** Last update Feb Jun 13 19:03:01 2016 Jonathan BITEAU
*/

#ifndef CIRC_BUFFER_H_
# define CIRC_BUFFER_H_

# include <stdlib.h>

# define CIRC_BUFF_SIZE (20 * 1024)

typedef struct	s_circ_buff
{
  int		pos;
  char		buff[CIRC_BUFF_SIZE + 1];
}		t_circ_buff;

t_circ_buff*	cb_create();
int		cb_write(t_circ_buff* buff, char* str);
void		cb_reset(t_circ_buff* buff);
void		cb_destroy(t_circ_buff* buff);

#endif /* CIRC_BUFFER_H_ */
