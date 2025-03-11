# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medayi <medayi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 10:00:00 by medayi            #+#    #+#              #
#    Updated: 2023/10/05 10:00:00 by medayi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CLIENT = client
SERVER = server
BONUS_CLIENT = client_bonus
BONUS_SERVER = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_CLIENT = client.c
SRCS_SERVER = server.c
SRCS_BONUS_CLIENT = client_bonus.c
SRCS_BONUS_SERVER = server_bonus.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_BONUS_CLIENT = $(SRCS_BONUS_CLIENT:.c=.o)
OBJS_BONUS_SERVER = $(SRCS_BONUS_SERVER:.c=.o)

LIBFTPRINTF = ft_printf/libftprintf.a
LIBFTPRINTF_DIR = ft_printf

all: $(NAME) clean
	@echo "Derlemeler tamamlandı."

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
	@$(MAKE) -C $(LIBFTPRINTF_DIR)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) $(LIBFTPRINTF)

$(SERVER): $(OBJS_SERVER)
	@$(MAKE) -C $(LIBFTPRINTF_DIR)
	@$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) $(LIBFTPRINTF)

bonus: $(BONUS_CLIENT) $(BONUS_SERVER)

$(BONUS_CLIENT): $(OBJS_BONUS_CLIENT)
	@$(MAKE) -C $(LIBFTPRINTF_DIR)
	@$(CC) $(CFLAGS) -o $(BONUS_CLIENT) $(OBJS_BONUS_CLIENT) $(LIBFTPRINTF)

$(BONUS_SERVER): $(OBJS_BONUS_SERVER)
	@$(MAKE) -C $(LIBFTPRINTF_DIR)
	@$(CC) $(CFLAGS) -o $(BONUS_SERVER) $(OBJS_BONUS_SERVER) $(LIBFTPRINTF)

clean:
	@$(MAKE) -C $(LIBFTPRINTF_DIR) clean
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_BONUS_CLIENT) $(OBJS_BONUS_SERVER)

fclean: clean
	@$(MAKE) -C $(LIBFTPRINTF_DIR) fclean
	@rm -f $(CLIENT) $(SERVER) $(BONUS_CLIENT) $(BONUS_SERVER)

re: fclean all

.PHONY: all clean fclean re bonus