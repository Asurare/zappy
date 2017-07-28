/*
** main.c for mainbn in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by biteau_j
** Login   <biteau_j@epitech.net>
**
** Started on  Tue Jun  7 18:15:47 2016 biteau_j
** Last update Feb Jun 20 16:28:31 2016 Jonathan BITEAU
*/

#include "client.h"

static char *usage()
{
  return ("Usage: \"./client -n teamname -h machine_name -p port\"");
}

int	main(int argc, char **argv)
{
  t_client	*cl;
  int ret;

  ret = 0;
  if (argc != 7)
    return (fprintf(stderr, BOLD RED "%s\n" RESET, usage()));
  init(&cl);
  if ((ret = server_connect(cl, argv)) > 0)
  {
    fprintf(stderr, BOLD RED "./ia : %s : wrong option\n%s\n" RESET,
            argv[ret], usage());
    ret = -1;
  }
  return (loop(cl, ret));
}
