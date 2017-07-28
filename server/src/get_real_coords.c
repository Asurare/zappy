/*
** get_real_coords.c for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy/src
** 
** Made by Florian Videau
** Login   <videau_f@epitech.net>
** 
** Started on  Sun Jun 19 10:10:43 2016 Florian Videau
** Last update Mon Jun 20 14:51:09 2016 Florian Videau
*/

#include "server.h"

long	get_real_x(long x)
{
  while (x < 0)
    x += g_args.x;
  return (x % g_args.x);
}

long	get_real_y(long y)
{
  while (y < 0)
    y += g_args.y;
  return (y % g_args.y);
}
