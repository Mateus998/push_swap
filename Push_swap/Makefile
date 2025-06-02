# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/22 14:17:30 by mateferr          #+#    #+#              #
#    Updated: 2025/06/02 15:35:13 by mateferr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

SRC = utils/ft_list.c utils/ft_split.c utils/ft_utils.c utils/wr_instructions.c\
utils/ps_instructions.c utils/r_instructions.c utils/ft_list2.c \
utils/input_val_utils.c \
ft_printf/ft_printf.c ft_printf/ft_printf_utils.c \
algotithms/sort_alg_utils.c algotithms/turk_sort.c \
algotithms/turk_sort_utils1.c algotithms/turk_sort_utils2.c \
input_validation.c
PUSH_SWAP = push_swap.c

BSRC = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c \
bonus/checker.c bonus/checker_utils.c

OBJ = $(SRC:.c=.o)
PSOBJ = $(PUSH_SWAP:.c=.o)
BOBJ = $(BSRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(PSOBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PSOBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(BOBJ) $(OBJ)
	$(CC) $(CFLAGS) $(BOBJ) $(OBJ) -o $(BONUS)

clean:
	rm -f $(OBJ) $(BOBJ) $(PSOBJ)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all