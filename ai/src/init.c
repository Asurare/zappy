/*
** init.c for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  Apr Jun 15 10:22:40 2016 Jonathan BITEAU
** Last update Jan Jun 26 02:33:52 2016 Jonathan BITEAU
*/

# include "client.h"

static int  get_random_id()
{
  unsigned int seed;

  seed = time(NULL);
  return (rand_r(&(seed)) % SHRT_MAX);
}

void init(t_client **client)
{
  if (((*client) = malloc(sizeof(t_client))) == NULL)
    return;
  (*client)->id = get_random_id();
  (*client)->ip = NULL;
  (*client)->connected = false;
  (*client)->run = true;
  (*client)->read = true;
  (*client)->buff = cb_create();
  (*client)->recv = cb_create();
  (*client)->size_seen = 0;
  (*client)->pos[0] = 0;
  (*client)->pos[1] = 0;
  (*client)->map[0] = 0;
  (*client)->lvl = 1;
  (*client)->max = 0;
  (*client)->ori = 0;
  (*client)->map[1] = 0;
  (*client)->st = AHEAD;
  (*client)->mode = VOIR;
  (*client)->br_mess = NULL;
  (*client)->inv = NULL;
  (*client)->seeing = NULL;
}
