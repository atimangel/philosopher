/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:21:57 by snpark            #+#    #+#             */
/*   Updated: 2021/07/31 21:00:04 by senoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
//printf
# include <stdlib.h>
//malloc free
# include <string.h>
//memset
# include <unistd.h>
//write usleep
# include <sys/time.h>
//gettimeofday
# include <pthread.h>

struct	s_philo;

typedef struct s_condition
{
	int	number;
	int	death;
	int	eat;
	int	sleep;
	int	need;
	pthread_mutex_t	*fork;
	struct s_philo	*philo;
	pthread_mutex_t	*mic;
	long	start_time;
}		t_condition;

typedef	struct	s_philo
{
	t_condition	*condition;
	int		id;
	int 	spaghetti;
	long	start_eat;
	long	limit;
	char	able_to_think;
	int		lfork;
	int		rfork;
}		t_philo;

/*
**init.c
*/
int	set_table(t_condition *condition);
/*
**char_to_num.c
*/
int	ft_atoi(const char *string);
/*
**exit.c
*/
int	exit_error(const char *msg);
/*
**timestamp.c
*/
long	timestamp(void);
#endif
