/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:49:07 by snpark            #+#    #+#             */
/*   Updated: 2021/08/16 21:34:49 by senoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** arg < 0	DEAD
** arg >= 0	ALIVE
*/

int	is_dead(const long long deadline)
{
	if (gettime() >= deadline)
		return (1);
	return (0);
}

void	ft_tmp(const long long deadline)
{
	while (gettime() <= deadline)
		usleep(32);
}


void	take_fork(const t_condition *const condition)
{
	sem_wait(condition->l_fork);
	printf("%d	%d has taken a fork\n", timestamp(condition->start_time), condition->id);
	sem_wait(condition->r_fork);
	printf("%d	%d has taken a fork\n", timestamp(condition->start_time), condition->id);
}

int	philo_eat(t_condition *condition)
{
	take_fork(condition);
	philo_message(condition->id, EAT, timestamp(condition->start_time));
	printf("%d	%d is eating\n", timestamp(condition->start_time), condition->id);
	ft_tmp(gettime() + condition->eat);
	condition->start_eat = gettime();
	sem_post(condition->l_fork);
	sem_post(condition->r_fork);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_condition *const condition = (t_condition *)arg;
	
	if (condition->spaghetti != -1)
	{
		while (condition->spaghetti)
		{
			philo_eat(condition);
			--condition->spaghetti;
			printf("%d	%d is sleeping\n", timestamp(condition->start_time), condition->id);
			ft_tmp(gettime() + condition->sleep);
			if (!condition->spaghetti)
				exit(0);
			printf("%d	%d is thinking\n", timestamp(condition->start_time), condition->id);
		}
	}
	else
	{
		while (1)
		{
			philo_eat(condition);
			printf("%d	%d is sleeping\n", timestamp(condition->start_time), condition->id);
			ft_tmp(gettime() + condition->sleep);
			printf("%d	%d is thinking\n", timestamp(condition->start_time), condition->id);
		}
	}
	return (NULL);
}

void	routine(t_condition *const condition)
{
	pthread_t	philo;

	if (pthread_create(&philo, NULL, philo_routine, condition))
		exit(1);
	pthread_detach(philo);
	while (1)
	{
		usleep(512);
		if (is_dead(condition->start_eat + condition->death))
		{
			sem_wait(condition->stop);
			philo_message(condition->id, DEATH, timestamp(condition->start_time));
			exit(1);
		}
	}
}
