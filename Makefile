# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aglampor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 15:05:19 by aglampor          #+#    #+#              #
#    Updated: 2024/08/07 20:39:25 by aglampor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = minishell

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

LDFLAGS = -lreadline

SRC_DIR = src/

SRC_FILES = build_ft.c env.c ft_split.c minishell.c utils.c split_ws.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
