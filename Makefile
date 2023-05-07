# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 01:24:15 by elakhfif          #+#    #+#              #
#    Updated: 2023/05/07 01:31:58 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC		=	cc
CFLAGS	=	-Werror -Wextra -Wall -O3
LIBFT	=	./libft/libft.a

SRCS	=	

OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(MAKE) -s bonus -C ./libft
	@$(CC) $(CFLAGS) $(LIBFT) -L$(shell brew --prefix readline)/lib -lreadline $^ -o $(NAME)
	@$(MAKE) -s clean -C ./libft

%.o: %.c minishell.h
	@$(CC) $(CFLAGS) -c -I$(shell brew --prefix readline)/include $< -o $@

all: $(NAME)

clean:
	@$(MAKE) -s clean -C ./libft
	@rm -rf $(OBJS)

fclean: clean
	@$(MAKE) -s fclean -C ./libft
	@rm -rf $(NAME)

re: fclean all
