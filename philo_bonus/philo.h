/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:21:57 by snpark            #+#    #+#             */
/*   Updated: 2021/09/16 14:08:46 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/wait.h>

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEATH 4

typedef struct s_condition
{
	int				number;
	int				death;
	int				eat;
	int				sleep;
	int				need;
	sem_t			*l_fork;	
	sem_t			*r_fork;	
	sem_t			*stop;
	long long		start_time;
	long long		start_eat;
	int				id;
	int				spaghetti;
	pid_t			*philos;
}					t_condition;

/*
**init.c
*/
int			set_table(t_condition *condition);
/*
**char_to_num.c
*/
int			ft_atoi(const char *string);
/*
**exit.c
*/
int			exit_error(const char *msg);
/*
**timestamp.c
*/
long long	gettime(void);
int			timestamp(const long long start);
void		ft_usleep(const long long deadline);
/*
**routune.c
*/
int			is_dead(const long long deadline);
void		routine(t_condition *const condition);
void		clean_table(t_condition *condition);
/*
**message.c
*/
void		philo_message(int id, char flag, int now);
#endif
