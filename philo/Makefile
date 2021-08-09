# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 13:11:34 by snpark            #+#    #+#              #
#    Updated: 2021/08/06 17:17:48 by snpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = char_to_num.c\
	exit.c\
	init.c\
	main.c\
	timestamp.c\
	routine.c\
	clean.c\
	ripper.c\
	message.c

NAME = philo

all : $(NAME)

$(NAME) :
	gcc -o $(NAME) $(SRC) -lpthread

clean :
	rm $(NAME)

fclean : clean

re : clean all

