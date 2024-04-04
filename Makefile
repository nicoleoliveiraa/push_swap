# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 15:18:19 by nsouza-o          #+#    #+#              #
#    Updated: 2024/04/04 15:47:37 by nsouza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS_PATH = ./srcs
BONUS_SRCS_PATH = ./bonus_srcs

BONUS_SRCS = $(BONUS_SRCS_PATH)/checker.c \
			$(BONUS_SRCS_PATH)/get_line.c

SRCS = $(SRCS_PATH)/algorithm2and3.c \
		$(SRCS_PATH)/check_index.c \
		$(SRCS_PATH)/check_parameters.c \
		$(SRCS_PATH)/get_elements.c \
		$(SRCS_PATH)/main.c \
		$(SRCS_PATH)/operations_p.c \
		$(SRCS_PATH)/operations_r.c \
		$(SRCS_PATH)/operations_s.c \
		$(SRCS_PATH)/operations_rr.c \
		$(SRCS_PATH)/stack.c \
		$(SRCS_PATH)/to_sort.c \
		$(SRCS_PATH)/to_sort_b_a.c \
		$(SRCS_PATH)/utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME)

clean: 
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean bonus re