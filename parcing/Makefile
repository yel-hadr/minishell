# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 05:40:27 by elakhfif          #+#    #+#              #
#    Updated: 2023/07/08 14:11:15 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC	=	cc
CFLAGS	=	-Werror -Wextra -Wall -O3
LIBFT	=	../libft/libft.a

SRCS	=	main.c\
		split_cmd.c\
		struct_cmd.c\
		split_args.c\
		parser.c\
		remove_quotes.c\
		checker.c\


OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	@printf "\033[1;36m Compiling \033[0m LIBFT \033[1;36m√\033[0m\n"
	@$(MAKE) -s all -C ../libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)
	@$(MAKE) -s clean -C ../libft
	@printf "\n\033[1;36m ───────────── Done ──────────── \033[0m\n\n"

%.o: %.c parser.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[1;36m Compiling \033[0m $< \033[1;36m√\033[0m\n"

all: $(NAME)

clean:
	@printf "\033[1;36m Deleting \033[0m libft OBJ \033[1;36m√\033[0m\n"
	@$(MAKE) -s clean -C ../libft
	@printf "\033[1;36m Deleting \033[0m minishell OBJ \033[1;36m√\033[0m\n"
	@rm -rf $(OBJS)
	@printf "\033[1;36m ───────────── Done ──────────── \033[0m\n\n"

fclean: clean
	@printf "\033[1;36m Deleting \033[0m LIBFT \033[1;36m√\033[0m\n"
	@$(MAKE) -s fclean -C ../libft
	@printf "\033[1;36m Deleting \033[0m $(NAME) \033[1;36m√\033[0m\n"
	@rm -rf $(NAME)
	@printf "\033[1;36m ───────────── Done ──────────── \033[0m\n\n"

re: fclean all
