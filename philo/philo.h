/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:21:57 by snpark            #+#    #+#             */
/*   Updated: 2021/08/04 20:07:53 by snpark           ###   ########.fr       */
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
	int		number;
	int		death;
	int		eat;
	int		sleep;
	int		need;
	pthread_mutex_t	*fork;
	struct s_philo	*philo;
	pthread_mutex_t	*mic;
	long long	start_time;
	int		test;
}		t_condition;

typedef	struct	s_philo
{
	t_condition	*condition;
	int		id;
	int	 	spaghetti;
	long long	start_eat;
	char		able_to_think;
	int		lfork;
	int		rfork;
	pthread_t thread_info; 
}		t_philo;

/*
**init.c
*/
int		set_table(t_condition *condition);
/*
**char_to_num.c
*/
int		ft_atoi(const char *string);
/*
**exit.c
*/
int		exit_error(const char *msg);
/*
**timestamp.c
*/
long long	gettime(void);
int		timestamp(long long start);
void		ft_usleep(int time);
/*
**routune.c
*/
void		*routine(void *arg);
/*
**clean.c
*/
int		clean_table(t_condition *condition);
#endif
