/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:49:07 by snpark            #+#    #+#             */
/*   Updated: 2021/09/05 14:07:53 by snpark           ###   ########.fr       */
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

	arg = philo->condition->death - timestamp(philo->start_eat);
	if (arg < 0)
		philo_message(philo, DEATH);
	return (arg);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->condition->m_fork + philo->lfork);
	philo_message(philo, FORK);
	pthread_mutex_lock(philo->condition->m_fork + philo->rfork);
	philo_message(philo, FORK);
}

int	philo_eat(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(philo->condition->mouth);
	philo->start_eat = gettime();
	++philo->spaghetti;
	pthread_mutex_unlock(philo->condition->mouth);
	philo_message(philo, EAT);
	ft_usleep(gettime() + philo->condition->eat * 1000);
	pthread_mutex_unlock(philo->condition->m_fork + philo->lfork);
	pthread_mutex_unlock(philo->condition->m_fork + philo->rfork);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->condition->stop == 1)
		;
	philo->start_eat = philo->condition->start_time;
	ft_usleep(gettime() + philo->id * 10);
	if (!(philo->id & 1))
		ft_usleep(gettime() + philo->condition->eat * 900);
	while (!philo->condition->stop)
	{
		if (philo_eat(philo))
		{
			pthread_mutex_unlock(philo->condition->m_fork);
			break ;
		}
		philo_message(philo, SLEEP);
		ft_usleep(gettime() + philo->condition->sleep * 1000);
		philo_message(philo, THINK);
	}
	return (NULL);
}
