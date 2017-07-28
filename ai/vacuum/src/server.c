/*
** server.c for server in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/src
**
** Made by biteau_j
** Login   <biteau_j@epitech.net>
**
** Started on  Tue Jun  7 18:15:36 2016 biteau_j
** Last update May Jun 23 14:33:06 2016 Jonathan BITEAU
*/

# include "client.h"

static char	*get_ip(char *str)
{
  int ct;
  int nbr;

  ct = -1;
  nbr = 0;
  if (strcmp("localhost", str) == 0)
    return (strdup("127.0.0.1"));
  while (str[++ct])
  {
    if (isdigit(str[ct]) != 0)
      continue;
    else if (str[ct] == '.')
      nbr += 1;
    else
      return (NULL);
  }
  if (nbr != 3)
    return (NULL);
  return (strdup(str));
}

static int	attemp_connection(t_client *cl)
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  int			fd;

  if ((pe = getprotobyname("TCP")) == NULL)
    return (-1);
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (-1);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(cl->port);
  s_in.sin_addr.s_addr = inet_addr(cl->ip);
  if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      perror(BOLD RED "Connect error");
      printf(RESET);
      free(cl->ip);
      cl->ip = NULL;
      return (-1);
    }
  cl->fd = fd;
  cl->connected = true;
  return (0);
}

char *is_valid_name(char *str)
{
  int ct;

  ct = 0;
  while (str[ct])
   {
     if (isalnum(str[ct++]) == 0)
      return (NULL);
   }
   return (str);
}

int parse_args(t_client *cl, char **args)
{
  int is_ok;
  int ct;

  is_ok = 0;
  ct = 0;
  while (args[++ct])
  {
    if (strcmp(args[ct], "-n") == 0 && args[ct + 1] &&
    (cl->team_name = is_valid_name(args[++ct])) != NULL)
      is_ok += 1;
    else if (strcmp(args[ct], "-p") == 0 && args[ct + 1] &&
    (cl->port = atoi(args[++ct])) != 0)
      is_ok += 1;
    else if (strcmp(args[ct], "-h") == 0 && args[ct + 1] &&
    (cl->ip = get_ip(args[++ct])) != NULL)
      is_ok += 1;
    else
      return (ct);
  }
  if (is_ok != 3)
    return (0);
  return (-1);
}

int	server_connect(t_client *cl, char **args)
{
  int ret;

  if ((ret = parse_args(cl, args)) >= 0)
    return (ret);
  if (attemp_connection(cl) == -1)
    return (-1);
  return (0);
}
