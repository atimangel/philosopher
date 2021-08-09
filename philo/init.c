/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:29:10 by snpark            #+#    #+#             */
/*   Updated: 2021/08/08 15:18:08 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_fork(t_condition *condition)
{
	int	i;

	condition->fork = malloc(condition->number);
	condition->m_fork = malloc(sizeof(pthread_mutex_t) * condition->number);
	if (!condition->m_fork)
		return (exit_error("Error: fork is missing\n"));
	i = 0;
	while (i < condition->number)
	{
		if (pthread_mutex_init(condition->m_fork + i, NULL))
			return (exit_error("Error: mutex init error"));
		condition->fork[i++] = 1;
	}
	return (0);
}

int	invite_philo(t_condition *condition)
{
	int	i;

	condition->philo = malloc(sizeof(t_philo) * condition->number);
	if (!condition->philo)
		return (exit_error("Error: philosofer refuse invitation\n"));
	i = 0;
	while (i < condition->number)
	{
		condition->philo[i].id = i + 1;
		condition->philo[i].spaghetti = 0;
		condition->philo[i].lfork = i;
		condition->philo[i].rfork = (i + 1) % condition->number;
		condition->philo[i].condition = condition;
		i++;
	}
	return (0);
}

int	set_mic(t_condition *condition)
{
	condition->mic = malloc(sizeof(pthread_mutex_t));
	condition->mouth = malloc(sizeof(pthread_mutex_t));
	if (!condition->mic)
		return (exit_error("Error: MIC is missing\n"));
	if (!condition->mouth)
		return (exit_error("Error: can't open mouth\n"));
	if (pthread_mutex_init(condition->mic, NULL))
		return (exit_error("Error: MIC is missing\n"));
	if (pthread_mutex_init(condition->mouth, NULL))
		return (exit_error("Error: can't open mouth\n"));
	return (0);
}

int	start_dinner(t_condition *condition)
{
	int		i;
	t_philo	*philo;

	philo = condition->philo;
	i = 0;
	condition->stop = 1;
	while (i < condition->number)
	{
		philo[i].start_eat = condition->start_time;
		if (pthread_create(&philo[i].thread_info, NULL, routine, philo + i))
			return (exit_error("Error: thread create error"));
		pthread_detach(philo[i++].thread_info);
	}
	condition->start_time = gettime();
	condition->stop = 0;
	usleep(50000);
	pthread_create(&condition->ripper, NULL, ripper, condition);
	pthread_join(condition->ripper, NULL);
}

int	set_table(t_condition *condition)
{
	if (set_fork(condition))
		return (1);
	if (invite_philo(condition))
		return (1);
	if (set_mic(condition))
		return (1);
	if (start_dinner(condition))
		return (1);
	return (0);
}
