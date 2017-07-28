/*
** msg.h for zappy in /home/work/work/projects/PSU_2015_zappy_doc/PSU_2015_zappy/include
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Jun 14 16:24:05 2016 Bastien DHIVER
** Last update Sun Jun 26 03:02:38 2016 Bastien DHIVER
*/

#ifndef MSG_H_
# define MSG_H_

# define LF			"\n"

# define ERR_PORT_NOT_INT	"The given port does not fit in an INT"LF
# define ERR_PORT_NOT_IN_RANGE	"Wrong port number"LF
# define ERR_WIDTH_NOT_LONG	"The specified width does not fit in a LONG"LF
# define ERR_WIDTH_LOWER_ZERO	"Width must be greater than zero"LF
# define ERR_HEIGHT_NOT_LONG	"The specified height does not fit in a LONG"LF
# define ERR_HEIGHT_LOWER_ZERO	"Height must be greater than zero"LF
# define ERR_ALLOWED_USERS_LONG	"Allowed users by team does not fit in a \
LONG"LF
# define ERR_ALLOWED_USERS_ZERO	"Allowed users must be greater than zero"LF
# define ERR_DELAY_LONG		"The given time delay does not fit in a LONG"LF
# define ERR_DELAY_ZERO		"The time delay must be greater than zero"LF
# define ERR_MALLOC		"Memory allocation error"LF
# define ERR_MISS_MANDATORY_OPT	"Missing mandatory option"

# define WELCOME_MSG_1		"BIENVENUE"LF
# define ELEVATION_IN_PROGRESS	"elevation en cours"LF
# define WELCOME_GRAPH_MSG	"GRAPHIC"

# define KO_MSG			"ko"LF
# define OK_MSG			"ok"LF
# define PLAYER_DEATH		"mort"LF

#endif /* MSG_H_ */
