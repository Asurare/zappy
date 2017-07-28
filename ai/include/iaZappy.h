/*
** iaZappy.h for zappy in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy/include
**
** Made by Jonathan BITEAU
** Login biteau_j <jonathan.biteau@epitech.eu>
**
** Started on  Jun Jun 24 22:40:38 2016 Jonathan BITEAU
** Last update Sun Jun 26 22:40:34 2016 Florian Videau
*/

#ifndef IDZAPPY_H_
# define IDZAPPY_H_

# include <string.h>

# define JOUEUR "joueur"
# define NOURRITURE "nourriture"
# define LINEMATE "linemate"
# define DERAUMERE "deraumere"
# define SIBUR "sibur"
# define MENDIANE "mendiane"
# define PHIRAS "phiras"
# define THYSTAME "thystame"

# define AVANCE "avance"
# define DROITE "droite"
# define GAUCHE "gauche"

# define LV1 "100000"
# define LV2 "111000"
# define LV3 "201020"
# define LV4 "112010"
# define LV5 "123010"
# define LV6 "222221"

# include "client.h"
# include "str_to_wordtab.h"

typedef struct	s_element
{
  int		pos;
  int		size;
  char		*value;
}		t_element;

/*
**orientation.c
*/
void	moveIA(t_client *, char *, int);
int	nbWord(char *, char);
int	nbWordCase(char *, char);
int	calcOrientation(t_client*);

/*
**alignement.c
*/
int	isInAlignement(char *, t_client *);
char	*formateTable(char *);
int	goodAlignement(t_client *);
int	goodAlignementMtp(t_client *);

/*
**pos.c
*/
int	definePos(t_client *);
void	calcPos(t_client *, char *, int);
void	otherPos(t_client * , int, char *);
int	finalValX(int, int);
int	calcX(char *, int, int *);
void	changeLigne(int *, int *);
void	setPos(t_client *, int, int);

int	onlyRessource(t_client *);
int	multipleRessource(t_client *client);

/*
**gestCase.c
*/
void	gestionCase(t_client *);

/*
**multipleR.c
*/
char	*cmpInv(t_client *);

/*
**formateTable.c
*/
char	*use_the_best(t_client *, char *);

#endif /* !IDZAPPY_H_ */
