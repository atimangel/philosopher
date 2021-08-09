/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:49:07 by snpark            #+#    #+#             */
/*   Updated: 2021/08/08 13:50:52 by snpark           ###   ########.fr       */
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

void	take_fork(t_philo *philo, int fork_num)
{
	pthread_mutex_lock(philo->condition->m_fork + fork_num);
	if (philo->condition->fork[fork_num]-- == 1)
		;
	else
	{
		printf("Error: %dfork is duplicating\n", fork_num);
		philo->condition->stop++;
	}
	philo_message(philo, FORK);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_t	*m_fork;

	m_fork = philo->condition->m_fork;
	take_fork(philo, philo->lfork);
	take_fork(philo, philo->rfork);
	pthread_mutex_lock(philo->condition->mouth);
	philo->start_eat = gettime();
	philo->spaghetti++;
	pthread_mutex_unlock(philo->condition->mouth);
	philo_message(philo, EAT);
	usleep(philo->condition->eat * 1000);
	philo->condition->fork[philo->lfork]++;
	pthread_mutex_unlock(m_fork + philo->lfork);
	philo->condition->fork[philo->rfork]++;
	pthread_mutex_unlock(m_fork + philo->rfork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->condition->stop == 1)
		;
	philo->start_eat = philo->condition->start_time;
	usleep(philo->id * 10);
	if (philo->id % 2 == 0)
		usleep(philo->condition->eat * 900);
	while (!philo->condition->stop)
	{
		philo_eat(philo);
		philo_message(philo, SLEEP);
		usleep(philo->condition->sleep * 1000);
		philo_message(philo, THINK);
	}
}
