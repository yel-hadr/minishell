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

NAME	=	parser.a
CC	=	cc
CFLAGS	=	-Werror -Wextra -Wall -O3
LIBFT	=	../libft/libft.a

SRCS	=	split_cmd.c\
		struct_cmd.c\
		split_args.c\
		parser.c\
		remove_quotes.c\
		checker.c\
		prompt.c\


OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c parser.h
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
