/*
** get_in_addr.c for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Jun 15 17:57:58 2016 Bastien DHIVER
** Last update Wed Jun 15 17:58:29 2016 Bastien DHIVER
*/

#include <netdb.h>

void	*get_in_addr(struct sockaddr *sa)
{
  if (sa->sa_family == AF_INET)
    return (&(((struct sockaddr_in *)sa)->sin_addr));
  return (&(((struct sockaddr_in6 *)sa)->sin6_addr));
}
