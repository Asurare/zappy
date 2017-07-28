##
## Makefile for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy
## 
## Made by Florian Videau
## Login   <videau_f@epitech.net>
## 
## Started on  Tue Jun 14 09:50:42 2016 Florian Videau
## Last update Sun Jun 26 22:28:39 2016 Florian Videau
##

RM	= rm -f

CC	= gcc

CFLAGS	+= -W -Wall -Wextra -pedantic -std=gnu99
CFLAGS	+= -I$(INCF)

LDFLAGS	+= -lm

NAME	= server

SRCF	= src/

INCF	= include/

SRCS	= $(SRCF)calc_dist.c			\
	  $(SRCF)calc_dist_p2.c			\
	  $(SRCF)catch_sigint.c			\
	  $(SRCF)check_levels.c			\
	  $(SRCF)client_leaving.c		\
	  $(SRCF)client_life.c			\
	  $(SRCF)cmd_avance_action.c		\
	  $(SRCF)cmd_avance.c			\
	  $(SRCF)cmd_broadcast_action.c		\
	  $(SRCF)cmd_broadcast.c		\
	  $(SRCF)cmd_connect_nbr.c		\
	  $(SRCF)cmd_droite_action.c		\
	  $(SRCF)cmd_droite.c			\
	  $(SRCF)cmd_expulse_action.c		\
	  $(SRCF)cmd_expulse.c			\
	  $(SRCF)cmd_fork_action.c		\
	  $(SRCF)cmd_fork.c			\
	  $(SRCF)cmd_gauche_action.c		\
	  $(SRCF)cmd_gauche.c			\
	  $(SRCF)cmd_incantation_action.c	\
	  $(SRCF)cmd_incantation.c		\
	  $(SRCF)cmd_inventaire_action.c	\
	  $(SRCF)cmd_inventaire.c		\
	  $(SRCF)cmd_pose_objet_action.c	\
	  $(SRCF)cmd_pose_objet.c		\
	  $(SRCF)cmd_prend_objet_action.c	\
	  $(SRCF)cmd_prend_objet.c		\
	  $(SRCF)cmd_user_bye.c			\
	  $(SRCF)cmd_user_hi_and_add.c		\
	  $(SRCF)cmd_user_states.c		\
	  $(SRCF)cmd_voir_action.c		\
	  $(SRCF)cmd_voir_action_utils.c	\
	  $(SRCF)cmd_voir.c			\
	  $(SRCF)epur_str.c			\
	  $(SRCF)find_egg.c			\
	  $(SRCF)find_egg_from_id.c		\
	  $(SRCF)find_user.c			\
	  $(SRCF)free_time_list.c		\
	  $(SRCF)get_in_addr.c			\
	  $(SRCF)get_nb_elem_in_userList.c	\
	  $(SRCF)get_real_coords.c		\
	  $(SRCF)get_team_idx_from_fd.c		\
	  $(SRCF)graphic/bct.c			\
	  $(SRCF)graphic/ebo.c			\
	  $(SRCF)graphic/eht.c			\
	  $(SRCF)graphic/enw.c			\
	  $(SRCF)graphic/find_user.c		\
	  $(SRCF)graphic/graphic.c		\
	  $(SRCF)graphic/mct.c			\
	  $(SRCF)graphic/msz.c			\
	  $(SRCF)graphic/pbc.c			\
	  $(SRCF)graphic/pdi.c			\
	  $(SRCF)graphic/pdr.c			\
	  $(SRCF)graphic/pex.c			\
	  $(SRCF)graphic/pfk.c			\
	  $(SRCF)graphic/pgt.c			\
	  $(SRCF)graphic/pic.c			\
	  $(SRCF)graphic/pie.c			\
	  $(SRCF)graphic/pin.c			\
	  $(SRCF)graphic/plv.c			\
	  $(SRCF)graphic/pnw.c			\
	  $(SRCF)graphic/ppo.c			\
	  $(SRCF)graphic/say_hi.c		\
	  $(SRCF)graphic/send_to_all_graph_b.c	\
	  $(SRCF)graphic/send_to_all_graph_e.c	\
	  $(SRCF)graphic/send_to_all_graph_p.c	\
	  $(SRCF)graphic/sgt.c			\
	  $(SRCF)graphic/smg.c			\
	  $(SRCF)graphic/tna.c			\
	  $(SRCF)handle_user_cmd.c		\
	  $(SRCF)how_many_data_in_fd.c		\
	  $(SRCF)how_many_in.c			\
	  $(SRCF)incantation.c			\
	  $(SRCF)incantation_high_level.c	\
	  $(SRCF)incantation_low_level.c	\
	  $(SRCF)init_map.c			\
	  $(SRCF)init_select_use.c		\
	  $(SRCF)kick_client.c			\
	  $(SRCF)main.c				\
	  $(SRCF)opt_nct_colon.c		\
	  $(SRCF)opt_pxyh_ask.c			\
	  $(SRCF)port_in_range.c		\
	  $(SRCF)remove_graph_client_from_fd.c	\
	  $(SRCF)remove_msgs_to_send_from_fd.c	\
	  $(SRCF)remove_time_actions_from_fd.c	\
	  $(SRCF)run_server.c			\
	  $(SRCF)send_msg.c			\
	  $(SRCF)serve_them_all.c		\
	  $(SRCF)str_split.c			\
	  $(SRCF)str_to_nbr.c			\
	  $(SRCF)types/box.c			\
	  $(SRCF)types/egg.c			\
	  $(SRCF)types/eggList.c		\
	  $(SRCF)types/user.c			\
	  $(SRCF)types/userList.c		\
	  $(SRCF)xmalloc.c			\
	  $(SRCF)zappy_time.c

OBJS	= $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
