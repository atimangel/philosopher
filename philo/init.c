/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snpark <snpark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:29:10 by snpark            #+#    #+#             */
/*   Updated: 2021/08/04 21:59:34 by snpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_fork(t_condition *condition)
{
	int i;

	condition->fork = malloc(sizeof(pthread_mutex_t) * condition->number);
	if (!condition->fork)
		return(exit_error("Error: fork is missing\n"));
	i = 0;
	while (i < condition->number)
	{
		pthread_mutex_init(condition->fork + i++, NULL);
//		printf("%i fork is set\n", i);
	}
	return (0);
}

int	invite_philo(t_condition *condition)
{
	int	i;

	condition->philo = malloc(sizeof(t_philo) * condition->number);
	if (!condition->philo)
		return(exit_error("Error: philosofer refuse invitation\n"));
	i = 0;
	while (i < condition->number)
	{
		condition->philo[i].id = i + 1;
		condition->philo[i].spaghetti = 0;
		condition->philo[i].lfork = i;
		condition->philo[i].rfork = (i + 1) % condition->number;
		condition->philo[i].able_to_think = 1;
		condition->philo[i].condition = condition;
		i++;
//		printf("id %i\nspaghetti %i\nlfork %i\nrfork %i\nable to think %i\n", condition->philo[i - 1].id, condition->philo[i - 1].spaghetti, condition->philo[i - 1].lfork, condition->philo[i - 1].rfork, condition->philo[i - 1].able_to_think);
	}
	return (0);
}

int	set_mic(t_condition *condition)
{
	condition->mic = malloc(sizeof(pthread_mutex_t));
	if (!condition->mic)
		return(exit_error("Error: MIC is missing\n"));
	if (pthread_mutex_init(condition->mic, NULL))
		return(exit_error("Error: MIC is missing\n"));
//	printf("MIC set\n");
	return (0);
}
/*
void	*who_are_you(void *arg)
{
	t_philo	*philo;
	int a;
	int	i;

	i = 0;

	philo = (t_philo *)arg;
	//printf("---------start--------\n%d\n",philo->thread_info);
	if (a = pthread_mutex_lock(philo->condition->mic))
		printf("Error: %d\n", a);
	while (i < 4)
	{
		printf("%dms %i philo introduce itself %i\n", timestamp() - philo->condition->start_time, philo->id, i);
		usleep(10000);
		i++;
	}
	//printf("%dms %i philo introduce itself %i\n", timestamp() - philo->condition->start_time, philo->id, i);
	pthread_mutex_unlock(philo->condition->mic);
//	printf("-------end-------\n");
}
*/
/*
void	*eat(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->condition->fork + philo->lfork);
	printf("%dms %d philo hold %i fork\n", timestamp(philo->condition->start_time), philo->id, philo->lfork);
	pthread_mutex_lock(philo->condition->fork + philo->rfork);
	printf("%dms %d philo hold %i fork\n", timestamp(philo->condition->start_time), philo->id, philo->rfork);
	philo->start_eat = timestamp(philo->condition->start_time);
	printf("%dms %d philo start eat\n", timestamp(philo->condition->start_time), philo->id);
	philo->limit = philo->start_eat + philo->condition->death;
	usleep(philo->condition->death * 1000);
	printf("%dms %d philo finish eat\n", timestamp(philo->condition->start_time), philo->id);
	pthread_mutex_unlock(philo->condition->fork + philo->lfork);
	printf("%dms %d philo drop %i fork\n", timestamp(philo->condition->start_time) , philo->id, philo->lfork);
	pthread_mutex_unlock(philo->condition->fork + philo->rfork);
	printf("%dms %d philo drop %i fork\n", timestamp(philo->condition->start_time), philo->id, philo->rfork);
}
*/
int	start_dinner(t_condition *condition)
{
	int	i;
	int	thread_end;

	condition->start_time = gettime();
	i = 0;
	while (i  < condition->number)
	{
		pthread_create(&condition->philo[i].thread_info, NULL, routine, condition->philo + i);
		usleep(1);
		i++;
	}
	pthread_create(&condition->ripper, NULL, ripper, condition);
	i = 0;
	while (i < condition->number)
	{
		if(pthread_detach(condition->philo[i].thread_info));
		i++;
	}
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
