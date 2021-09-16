/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:49:07 by snpark            #+#    #+#             */
/*   Updated: 2021/09/16 17:06:52 by snpark           ###   ########.fr       */
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

void	take_fork(const t_condition *const condition)
{
	sem_wait(condition->fork);
	printf("%d	%d has taken a fork\n", \
	timestamp(condition->start_time), condition->id);
	sem_wait(condition->fork);
	printf("%d	%d has taken a fork\n", \
	timestamp(condition->start_time), condition->id);
}

int	philo_eat(t_condition *condition)
{
	take_fork(condition);
	printf("%d	%d is eating\n", \
	timestamp(condition->start_time), condition->id);
	condition->start_eat = gettime();
	ft_usleep(gettime() + condition->eat);
	sem_post(condition->fork);
	sem_post(condition->fork);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_condition *const	condition = (t_condition *)arg;

	while (condition->spaghetti)
	{
		philo_eat(condition);
		if (condition->spaghetti != -1)
			--condition->spaghetti;
		printf("%d	%d is sleeping\n", \
		timestamp(condition->start_time), condition->id);
		ft_usleep(gettime() + condition->sleep);
		if (!condition->spaghetti)
			exit(0);
		printf("%d	%d is thinking\n", \
		timestamp(condition->start_time), condition->id);
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
			printf("%d	%d died\n", \
			timestamp(condition->start_time), condition->id);
			exit(1);
		}
	}
}
