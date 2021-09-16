# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snpark <snpark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 13:11:34 by snpark            #+#    #+#              #
#    Updated: 2021/09/16 16:05:48 by snpark           ###   ########.fr        #
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

SRCS = $(SRC:%=./philo/%)
OBJ = $(SRCS:%.c=%.o)

BONUS_SRC = main.c\
	init.c\
	routine.c\
	timestamp.c\
	char_to_num.c

BONUS_SRCS = $(BONUS_SRC:%=./philo_bonus/%)
BONUS_OBJ = $(BONUS_SRCS:%.c=%.o)

NAME = philo

CPPFLAG = -pthread

all : $(NAME)

%.o : %.c
	gcc $(CPPFLAG) -c -o $@ $<

$(NAME) : $(OBJ)
	gcc -o ./$(NAME)/$(NAME) $(OBJ) $(CPPFLAG) 

$(NAME)_bonus : $(BONUS_OBJ)
	gcc -o ./$(NAME)_bonus/$(NAME)_bonus $(BONUS_OBJ) $(CPPFLAG) 

bonus : $(NAME)_bonus

clean :
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -rf ./philo/philo ./philo_bonus/philo_bonus

re : clean all

