##
## Makefile for makefile in /home/biteau_j/rendu/tek2/PSU/PSU_2015_zappy
##
## Made by biteau_j
## Login   <biteau_j@epitech.net>
##
## Started on  Tue Jun  7 18:14:19 2016 biteau_j
## Last update Sun Jun 26 22:29:11 2016 Bastien DHIVER
##

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-I ./include -W -Wall -Wextra -Werror -I ./include/

CLIENT	= 	ai

DSRC	=	src/

SRCSC	=	$(DSRC)main.c			\
		$(DSRC)str_to_wordtab.c		\
		$(DSRC)read_write.c		\
		$(DSRC)set_fds.c		\
		$(DSRC)loop.c			\
		$(DSRC)server.c			\
		$(DSRC)determine_action.c		\
		$(DSRC)actions.c		\
		$(DSRC)init.c		\
		$(DSRC)finders.c		\
		$(DSRC)circ_buffer.c		\
		$(DSRC)inv_and_see.c		\
		$(DSRC)broadcast.c	\
		$(DSRC)lin.c	\
		$(DSRC)take_food.c	\
		$(DSRC)counts.c	\
		$(DSRC)der.c	\

OBJSC	=	$(SRCSC:.c=.o)

all :		$(OBJSC)
		$(CC) -o $(CLIENT) $(OBJSC) -lm

clean :
		$(RM) $(OBJSS) $(OBJSC)

git-list:
	@git ls-tree -rt HEAD | cut -f 2 | sed -ne "s/SDL.*\.h//;t;p" | sed -e "s/[^\/]*\//    /g"

fclean :	clean
		$(RM) $(CLIENT)

re :		fclean all

.PHONY:		all clean fclean re
