##
## Makefile for zappy in /home/videau_f/rendu/PSU/PSU_2015_zappy
## 
## Made by Florian Videau
## Login   <videau_f@epitech.net>
## 
## Started on  Tue Jun 14 09:50:42 2016 Florian Videau
## Last update Sun Jun 26 22:09:01 2016 Bastien DHIVER
##

RM		= rm -f

SRV_PATH	= server

AI_PATH		= ai

SRV_NAME	= zappy_$(SRV_PATH)
AI_NAME		= zappy_$(AI_PATH)


all: $(SRV_NAME) $(AI_NAME)

$(SRV_NAME):
	$(MAKE) -C $(SRV_PATH)/
	mv $(SRV_PATH)/$(SRV_PATH) $(SRV_NAME)

$(AI_NAME):
	$(MAKE) -C $(AI_PATH)/
	mv $(AI_PATH)/$(AI_PATH) $(AI_NAME)

clean:
	$(MAKE) clean -C $(SRV_PATH)/
	$(MAKE) clean -C $(AI_PATH)/

fclean: clean
	$(MAKE) fclean -C $(SRV_PATH)/
	$(MAKE) fclean -C $(AI_PATH)/
	$(RM) $(SRV_NAME)
	$(RM) $(AI_NAME)

re: fclean all

.PHONY: all clean fclean re
