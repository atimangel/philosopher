/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:49:07 by snpark            #+#    #+#             */
/*   Updated: 2021/08/05 12:22:54 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** arg < 0	DEAD
** arg >= 0	ALIVE
*/

int	is_dead(t_philo *philo)
{
	int	arg;

	arg = philo->condition->death -
		(gettime() - philo->start_eat) / 1000;
	if (arg < 0)
	{
		printf("%dms	%d philo die	%d\n",
			timestamp(philo->condition->start_time), philo->id, arg);
	}
	return(arg);
}


void	philo_eat(t_philo *philo)
{
	pthread_mutex_t	*fork;
	long long	start;

	fork = philo->condition->fork;
	start = philo->condition->start_time;
	pthread_mutex_lock(fork + philo->lfork);
	philo->spaghetti++;
	philo_message(philo, FORK);
	pthread_mutex_lock(fork + philo->rfork);
	philo_message(philo, FORK);
	philo->start_eat = gettime();
	philo_message(philo, EAT);
	ft_usleep(philo->condition->eat * 1000);
	pthread_mutex_unlock(fork + philo->lfork);
	pthread_mutex_unlock(fork + philo->rfork);
}

void	philo_sleep(t_philo *philo)
{
	philo_message(philo, SLEEP);
	ft_usleep(philo->condition->sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	philo_message(philo, THINK);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->start_eat =
		philo->condition->start_time;
	while(!philo->condition->stop)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}
