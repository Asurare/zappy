/*
** circ_buffer.c for buff in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by biteau_j
** Login   <biteau_j@epitech.net>
**
** Started on  Mon Jun 13 18:58:40 2016 biteau_j
** Last update Feb Jun 13 19:02:58 2016 Jonathan BITEAU
*/

# include "../include/circ_buffer.h"

t_circ_buff	*cb_create()
{
  t_circ_buff	*alloc;

  if ((alloc = malloc(sizeof(t_circ_buff))) == NULL)
    return (NULL);
  alloc->pos = 0;
  alloc->buff[0] = '\0';
  return (alloc);
}

int	cb_write(t_circ_buff* buff, char* str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && buff->pos + i < CIRC_BUFF_SIZE)
    {
      buff->buff[i + buff->pos] = str[i];
      ++i;
    }
  buff->buff[i + buff->pos] = '\0';
  buff->pos += i;
  return (str[i] == '\0');
}

void	cb_reset(t_circ_buff* buff)
{
  buff->pos = 0;
  buff->buff[0] = '\0';
}

void	cb_destroy(t_circ_buff* buff)
{
  free(buff);
}
